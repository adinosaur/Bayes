//
// Date: 2015/09/10
//

#ifndef BAYES_ITEM_H
#define BAYES_ITEM_H

#include <memory>
#include <vector>

// Items类
// 封装了一个N维向量
// 通过保存智能指针，使得复制高效
class Items
{
    public:
        Items() = default;
        Items(const std::vector<int>&);
        Items(std::vector<int>&&);
        Items(std::initializer_list<int>&&);
        
        // 
        // 返回向量的维度
        // 
        int size();
        
        // 通过定义下标运算符operator[],begin,end迭代器
        // 来访问Items类封装的N维向量
        // 对于Items类使用者来说应该察觉不到Items内部保存指针的事实
        int operator[](int);
        std::vector<int>::iterator begin();
        std::vector<int>::iterator end();
    private:
        // 维护一个指向vector的向量
        std::shared_ptr<std::vector<int>> _p_items = nullptr;
};

#endif
