//
// Date: 2015/09/10
//

#ifndef BAYES_DOCUMENT_H
#define BAYES_DOCUMENT_H

#include "Item.h"
#include "Dictionary.h"

#include <assert.h>

#include <vector>
#include <ostream>

//
// Document
//
class Document
{
    public:
        Document(): 
            _dimension(0),
            _items(_dimension)
        {
        }
        
        Document(std::vector<int>&& item):
            _dimension(item.size()),
            _items(std::move(item)) 
        {
        }
        
        Document(std::initializer_list<int>&& lst):
            _dimension(lst.size())
        {
            for (auto&& item : lst)
                _items.push_back(std::move(item));
        }
        
        template <typename K>
        std::vector<Item<K,int>> translate(Dictionary<K>* dict)
        {
            assert(dict != nullptr);
            
            std::vector<Item<K,int>> result;
            
            for (int i = 0; i != _items.size(); ++i)
                result.push_back(std::move(Item<K, int>(dict->_id_to_word[i], _items[i])));
            return std::move(result);
        }
        
        //
        // get items
        //
        const std::vector<int>& items()
        {
            return _items;
        }
        
        //
        // get num of item 
        //
        int length()
        {
            return _dimension;
        }
        
        //
        // print items of a document
        //
        void print(std::ostream& os)
        {
            os << "[ ";
            for (std::vector<int>::size_type i = 0; 
                i != _items.size(); ++i)
            {
                os << "(" << i << ", ";
                os << _items[i] << "), ";
            }
            os << " ]" << std::endl;
        }
    private:
        int _dimension;
        std::vector<int> _items;

};

#endif
