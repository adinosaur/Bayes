//
// Date: 2015/09/10
//

#ifndef BAYES_TRAINING_H
#define BAYES_TRAINING_H

//#include "noncopyable.h"
#include "Document.h"

#include <assert.h>

#include <unordered_set>
#include <vector>
#include <numeric>

class Document;

class Training
{
    public:
        typedef std::vector<int> DocCategoryDistributionType;
        typedef std::vector<std::vector<int>> ItemCategoryDistributionType;
        
        // 
        // construct with num of category
        // 
        explicit Training(int categories, int dimension): 
            _categories(categories),
            _doc_category_distribution_done(false),
            _item_category_distribution_done(false),
            _documents(),
            _documents_to_category(),
            _category_total(_categories, 0),
            _doc_category_distribution(_categories, 0),
            _item_category_distribution(_categories, std::move(std::vector<int>(dimension)))
        {
        }
        
        //
        // add a document
        //
        void add_document(Document& d, int category)
        {
            _documents.push_back(&d);
            _documents_to_category.push_back(category);
        }
        
        //
        // get _doc_category_distribution
        //
        const DocCategoryDistributionType&
        document_category_distribution()
        {
            if (!_doc_category_distribution_done)
                _document_category_probability();
            
            return _doc_category_distribution;
        }
        
        //
        // get _item_category_distribution
        //
        const ItemCategoryDistributionType&
        item_category_distribution()
        {
            if (!_item_category_distribution_done)
                _document_item_probability();
            
            return _item_category_distribution;
        }
        
        //
        // Biyes classification algorithm
        // This function must be called after 
        // calling document_category_distribution() and item_category_distribution()
        //
        std::vector<double> bayes(Document& d)
        {
            assert(_doc_category_distribution_done);
            assert(_item_category_distribution_done);
            
            std::vector<double> result(_categories);
            
            // 遍历所有类别，对于每一个类别计算出这个Document属于该类别的概率
            for (typename std::vector<int>::size_type cid = 0; 
                cid != _doc_category_distribution.size(); ++cid)
            {
                // 先验概率
                double probability = (_doc_category_distribution[cid] / static_cast<double>(_documents.size()));
                
                // 该类别下给定的Document出现的概率
                // 等于类别下Document中的每个item出现的概率的乘积
                const std::vector<int>& items = d.items();
                
                // 得到该类别下item总权重大小
                int total = _category_total[cid];
                
                for (typename std::vector<int>::size_type i = 0; 
                    i != items.size(); ++i)
                {
                    if (_item_category_distribution[cid][i] > 0)
                    {
                        probability *= (_item_category_distribution[cid][i] / static_cast<double>(total));
                    }
                }
                result[cid] = probability;
            }
            
            // 归一化
            double all = std::accumulate(result.begin(), result.end(), 0.0);
            for (auto& x : result)
                x /= all;
            
            return result;
        }
        
    private:
        //
        // calculate document category distribution
        //
        void _document_category_probability()
        {
            // 计算出 类别-document 向量
            // 统计出类别的先验概率
            
            for (typename std::vector<int>::size_type id = 0; 
                id != _documents_to_category.size(); ++id)
            {
                ++_doc_category_distribution[_documents_to_category[id]];
            }
            _doc_category_distribution_done = true;
        }
        
        //
        // calculate document item distribution
        //
        void _document_item_probability()
        {
            // 计算出 类别-item 向量
            // 统计每一个类别中每一个item的出现频率
            
            // 遍历所有Document
            for (typename std::vector<int>::size_type id = 0; 
                id != _documents_to_category.size(); ++id)
            {
                // 得到该Document的类别编号
                int cate = _documents_to_category[id];
                
                // 得到Document的item向量
                const std::vector<int>& items = _documents[id]->items();
                
                // 对于该Document的每一维度的item，更新该类别的该item对应的值
                for (typename std::vector<int>::size_type i = 0; 
                    i != items.size(); ++i)
                {
                    _item_category_distribution[cate][i] += items[i];
                    
                    // 跟新_category_total
                    _category_total[cate] += items[i];
                }
            }
            _item_category_distribution_done = true;
        }
        
        // 类别数
        int _categories;
        
        bool _doc_category_distribution_done;
        bool _item_category_distribution_done;
        
        // 下标是文档id
        std::vector<Document*> _documents;
        std::vector<int> _documents_to_category;
        
        // 下标是类别id
        // 保存每一个类别的所有item.value之和
        std::vector<int> _category_total;
        
        DocCategoryDistributionType _doc_category_distribution;
        ItemCategoryDistributionType _item_category_distribution;
};

#endif
