//
// Date: 2015/09/20
//

#include "Items.h"
#include "Document.h"
#include "Dictionary.h"

#include <assert.h>

#include <string>
#include <ostream>
#include <unordered_map>

using namespace std;

Dictionary* Document::_p_dictionary = nullptr;

Document::Document(const string& content)
{
    _items = modeling(content);
}

// Document类的静态方法
void Document::set_dictionary(Dictionary& dict)
{
    _p_dictionary = &dict;
}

// 简单词袋模型
Items Document::modeling(const string& text)
{
    assert(_p_dictionary != nullptr);
    vector<int> vec(_p_dictionary->size(), 0);

    // 构建哈希表
    unordered_map<string,int> hash_table;
    string word;

    for (auto c : text)
    {
        if (c == ' ' && !word.empty())
        {
            hash_table[word]++;
            word.clear();
        }
        else
        {
            word.push_back(c);
        }
    }
    hash_table[word]++;
    
    // 构建词向量
    for (int i = 0; i != _p_dictionary->size(); ++i)
    {
        string w = _p_dictionary->_id_to_word[i];
        if (hash_table.find(w) != hash_table.end())
            vec[i] = hash_table[w];
    }
    
    return Items(vec);
}

Items Document::items()
{
    return _items;
}


void Document::print(ostream& os)
{
    os << "[";
    for (int i = 0; i != _items.size(); ++i)
        os << "(" << i << "," << _items[i] << "),";
    os << "]" << endl;
}
