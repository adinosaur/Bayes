//
// Date: 2015/10/06
//

#include "Modeling.h"
#include "Items.h"
#include "Dictionary.h"

#include <vector>

using namespace std;

WordBagModel::WordBagModel(Dictionary* p_dictionary):
    _p_dictionary(p_dictionary)
{
}

Items WordBagModel::operator()(const string& text)
{
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
        } else {
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
