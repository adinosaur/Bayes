//
// Date: 2015/09/10
//

#ifndef BAYES_TRAINING_H
#define BAYES_TRAINING_H

//#include "noncopyable.h"

#include <unordered_set>
#include <vector>

class Document;

class Training
{
    public:
        typedef std::vector<int> DocCategoryDistributionType;
        typedef std::vector<std::vector<int>> ItemCategoryDistributionType;
        
        // 
        // 构造函数
        // 参数分别是类别总数和每个向量的维度
        // 
        Training(int, int);
        
        //
        // 添加Document和所属类别ID
        //
        void add_document(Document&, int);
        
        //
        // 计算 Document-类别 概率分布
        //
        const DocCategoryDistributionType&
        document_category_distribution();
        
        //
        // 计算 item-类别 概率分布
        //
        const ItemCategoryDistributionType&
        item_category_distribution();
        
        //
        // 朴素贝叶斯分类算法
        // 该函数调用前必须调用 
        // document_category_distribution() 和 item_category_distribution()
        //
        std::vector<double> bayes(Document& d);
        
    private:
        //
        // 计算 Document-类别 概率分布
        //
        void _document_category_probability();
        
        //
        // 计算 item-类别 概率分布
        //
        void _document_item_probability();
        
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
