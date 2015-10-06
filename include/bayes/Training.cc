//
// Date: 2015/09/20
//

//#include "noncopyable.h"
#include "Training.h"
#include "Items.h"
#include "Document.h"

#include <assert.h>

#include <unordered_set>
#include <vector>
#include <numeric>

using namespace std;

Training::Training(int categories, int dimension): 
    _categories(categories),
    _doc_category_distribution_done(false),
    _item_category_distribution_done(false),
    _documents(),
    _documents_to_category(),
    _category_total(_categories, 0),
    _doc_category_distribution(_categories, 0),
    _item_category_distribution(_categories, std::move(vector<int>(dimension)))
{
}

void Training::add_document(Document& d, int category)
{
    _documents.push_back(&d);
    _documents_to_category.push_back(category);
}


void Training::training()
{
    // 训练得出 Document-类别 概率分布
    document_category_distribution();
    
    // 训练得出 Item-类别 概率分布
    item_category_distribution();
}


const vector<int>&
Training::document_category_distribution()
{
    if (!_doc_category_distribution_done)
        _document_category_probability();

    return _doc_category_distribution;
}

const vector<vector<int>>&
Training::item_category_distribution()
{
    if (!_item_category_distribution_done)
        _document_item_probability();

    return _item_category_distribution;
}

vector<double> Training::bayes(Document& d)
{
    assert(_doc_category_distribution_done);
    assert(_item_category_distribution_done);
    
    vector<double> result(_categories);

    // 遍历所有类别，对于每一个类别计算出这个Document属于该类别的概率
    for (typename vector<int>::size_type cid = 0; 
        cid != _doc_category_distribution.size(); ++cid)
    {
        // 先验概率
        double probability = (_doc_category_distribution[cid] / static_cast<double>(_documents.size()));
        
        // 该类别下给定的Document出现的概率
        // 等于类别下Document中的每个item出现的概率的乘积
        Items items = d.items();
        
        // 得到该类别下item总权重大小
        int cid_total = _category_total[cid];
        int items_total = accumulate(items.begin(), items.end(), 0);
        
        for (int i = 0; i != items.size(); ++i)
        {
            if (items[i] > 0 && _item_category_distribution[cid][i] > 0)
            {
                probability *= ((items[i] / static_cast<double>(items_total)) 
                    * (_item_category_distribution[cid][i]) / static_cast<double>(cid_total));
            }
            else
            {
                // 平滑0概率
                probability *= 0.01;
            }
        }
        result[cid] = probability;
    }
    
    // 归一化
    double all = accumulate(result.begin(), result.end(), 0.0);
    for (auto& x : result)
        x /= all;
    
    return result;
}


void Training::_document_category_probability()
{
    // 计算出 类别-document 向量
    // 统计出类别的先验概率
    
    for (typename vector<int>::size_type id = 0; 
        id != _documents_to_category.size(); ++id)
    {
        ++_doc_category_distribution[_documents_to_category[id]];
    }
    _doc_category_distribution_done = true;
}


void Training::_document_item_probability()
{
    // 计算出 类别-item 向量
    // 统计每一个类别中每一个item的出现频率

    // 遍历所有Document
    for (typename vector<int>::size_type id = 0; 
        id != _documents_to_category.size(); ++id)
    {
        // 得到该Document的类别编号
        int cate = _documents_to_category[id];
        
        // 得到Document的item向量
        Items items = _documents[id]->items();
        
        // 对于该Document的每一维度的item，更新该类别的该item对应的值
        for (int i = 0; i != items.size(); ++i)
        {
            _item_category_distribution[cate][i] += items[i];
            
            // 跟新_category_total
            _category_total[cate] += items[i];
        }
    }
    _item_category_distribution_done = true;
}
