//
// Date: 2015/09/21
//

#include "../include/bayes/Dictionary.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>

using namespace std;

TEST(BAYES_DICTIONARY, DICTIONARY_INITIALIZER_LIST_CONSTRUCTOR)
{
    Dictionary dictionary = {"hello" ,"world", "python", "cpp", "function", "favourite"};
    
    // 测试字典大小
    EXPECT_EQ(dictionary.size(), 6);
    
    // 测试单词->单词ID映射
    EXPECT_EQ(dictionary._word_to_id["hello"], 0);
    EXPECT_EQ(dictionary._word_to_id["world"], 1);
    EXPECT_EQ(dictionary._word_to_id["python"], 2);
    EXPECT_EQ(dictionary._word_to_id["cpp"], 3);
    EXPECT_EQ(dictionary._word_to_id["function"], 4);
    EXPECT_EQ(dictionary._word_to_id["favourite"], 5);
    
    // 测试单词ID->单词映射
    EXPECT_EQ(dictionary._id_to_word[0], "hello");
    EXPECT_EQ(dictionary._id_to_word[1], "world");
    EXPECT_EQ(dictionary._id_to_word[2], "python");
    EXPECT_EQ(dictionary._id_to_word[3], "cpp");
    EXPECT_EQ(dictionary._id_to_word[4], "function");
    EXPECT_EQ(dictionary._id_to_word[5], "favourite");
}

TEST(BAYES_DICTIONARY, DICTIONARY_VECTOR_CONSTRUCTOR)
{
    Dictionary dictionary(vector<string>({"hello" ,"world", "python", "cpp", "function", "favourite"}));
    
    // 测试字典大小
    EXPECT_EQ(dictionary.size(), 6);
    
    // 测试单词->单词ID映射
    EXPECT_EQ(dictionary._word_to_id["hello"], 0);
    EXPECT_EQ(dictionary._word_to_id["world"], 1);
    EXPECT_EQ(dictionary._word_to_id["python"], 2);
    EXPECT_EQ(dictionary._word_to_id["cpp"], 3);
    EXPECT_EQ(dictionary._word_to_id["function"], 4);
    EXPECT_EQ(dictionary._word_to_id["favourite"], 5);
    
    // 测试单词ID->单词映射
    EXPECT_EQ(dictionary._id_to_word[0], "hello");
    EXPECT_EQ(dictionary._id_to_word[1], "world");
    EXPECT_EQ(dictionary._id_to_word[2], "python");
    EXPECT_EQ(dictionary._id_to_word[3], "cpp");
    EXPECT_EQ(dictionary._id_to_word[4], "function");
    EXPECT_EQ(dictionary._id_to_word[5], "favourite");
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
