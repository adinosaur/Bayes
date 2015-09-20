//
// Date: 2015/09/10
//

#ifndef BAYES_ITEM_H
#define BAYES_ITEM_H

template<typename K, typename V>
class Item
{
    public:
        typedef K key_type;
        typedef V value_type;
        
        Item() = default;
        Item(key_type k, value_type v): key(k), value(v) {}
        
        key_type key;
        value_type value;
};

#endif
