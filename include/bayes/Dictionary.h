//
// Date:2015/09/11
//

#ifndef BAYES_DICTIONARY_H
#define BAYES_DICTIONARY_H

#include <unordered_map>
#include <vector>
#include <string>

// 
// Dictionary类
// 该类维护从单词ID到单词的双向映射
// 
class Dictionary
{
    public:
        //Dictionary() = default;
        explicit Dictionary(const std::vector<std::string>&);
        Dictionary(std::initializer_list<std::string>);

        // 
        // 返回字典的维度
        // 
        int size();

        // 单词->单词ID映射
        std::unordered_map<std::string, int> _word_to_id;
        
        // 单词ID>单词映射
        std::unordered_map<int, std::string> _id_to_word;
};

#endif
