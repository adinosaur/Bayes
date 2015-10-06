//
// Date: 2015/09/10
//

#ifndef BAYES_DOCUMENT_H
#define BAYES_DOCUMENT_H

#include "Items.h"

#include <assert.h>

#include <functional>
#include <ostream>
#include <unordered_map>

class Items;

//
// Document类
// 该类的主要功能是将一个Document抽象建模为一个N维的向量Item
//
template <typename T>
class Document
{
    public:
        typedef std::function<Items(T)> ModelingType;
        
        //
        // 构造函数
        //
        Document(const T& raw):
            _raw(raw),
            _items_flag(false),
            _items()
        {
        }
        
        //
        // 返回经过建模的抽象向量,被Training对象调用
        //
        Items items()
        {
            assert(_modeling);
            
            if (!_items_flag)
                _items = _modeling(_raw);
            return _items;
        }
        
        //
        // 打印Items向量
        //
        void print(std::ostream& os)
        {
            os << "[";
            for (int i = 0; i != _items.size(); ++i)
                os << "(" << i << "," << _items[i] << "),";
            os << "]" << std::endl;
        }
        
        //
        // 静态方法，设置建模方法
        //
        static void set_modeling(ModelingType modeling)
        {
            _modeling = modeling;
        }

    private:
        T _raw;
        bool _items_flag;
        Items _items;
        
        static ModelingType _modeling;
};

template <typename T>
typename Document<T>::ModelingType Document<T>::_modeling;

#endif
