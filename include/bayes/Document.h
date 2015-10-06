//
// Date: 2015/09/10
//

#ifndef BAYES_DOCUMENT_H
#define BAYES_DOCUMENT_H

#include "Items.h"

#include <string>
#include <ostream>
#include <unordered_map>

class Dictionary;
//class Items;

//
// Document类
// 该类的主要功能是将一个文本string抽象建模为一个N维的向量Item
// 默认的建模方法是Bag Of Word（词袋模型）
//
class Document
{
    public:
        //
        // 构造函数
        //
        Document(const std::string&);
        
        //
        // 静态方法，设置Document类的字典
        //
        static void set_dictionary(Dictionary&);
        
        //
        // 虚函数，子类通过override该函数实现自定义建模方法
        //
        virtual Items modeling(const std::string&);
        
        //
        // 返回经过建模的抽象向量,被Training对象调用
        //
        Items items();
        
        //
        // 打印Items向量
        //
        void print(std::ostream&);

    private:
        // Items向量
        Items _items;
        static Dictionary* _p_dictionary;
};

#endif
