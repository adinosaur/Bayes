//
// Date:2015/09/11
//

#ifndef BAYES_DICTIONARY_H
#define BAYES_DICTIONARY_H

#include <unordered_map>
#include <vector>

template <typename K>
class Dictionary
{
    public:
        Dictionary() = default;
        
        explicit Dictionary(const std::vector<K>& dict)
        {
            for (typename std::vector<K>::size_type i = 0; 
                i != dict.size(); ++i)
            {
                _word_to_id[dict[i]] = i;
                _id_to_word[i] = dict[i];
            }
        }
        
        Dictionary(std::initializer_list<K> lst)
        {
            int i = 0;
            for (auto item : lst)
            {
                _word_to_id[item] = i;
                _id_to_word[i] = item;
                i++;
            }
        }

        std::unordered_map<K, int> _word_to_id;
        std::unordered_map<int, K> _id_to_word;
};

#endif
