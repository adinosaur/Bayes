//
// Date: 2015/09/20
//

#include "Dictionary.h"

#include <vector>
#include <string>

using namespace std;

Dictionary::Dictionary(const vector<string>& dict)
{
    for (typename vector<string>::size_type i = 0; 
        i != dict.size(); ++i)
    {
        _word_to_id[dict[i]] = i;
        _id_to_word[i] = dict[i];
    }
}

Dictionary::Dictionary(std::initializer_list<string> lst)
{
    int i = 0;
    for (auto item : lst)
    {
        _word_to_id[item] = i;
        _id_to_word[i] = item;
        i++;
    }
}

int Dictionary::size()
{
    return _word_to_id.size();
}
