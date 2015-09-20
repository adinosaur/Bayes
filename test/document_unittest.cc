//
// Date: 2015/09/21
//

#include "../include/bayes/Document.h"
#include "../include/bayes/Dictionary.h"
#include "../include/bayes/Items.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>

using namespace std;

TEST(BAYES_DOCUMENT, DOCUMENT_MODEL)
{
    string text("I like football watching football matches every week occasionally playing football game");

    // 定义字典
    Dictionary dictionary = { "football", "match", "coldplay", "greenday", "java", "python" };
    
    // 设置Document的静态属性字典
    Document::set_dictionary(dictionary);
    Document d1(text);
    
    // 测试虚函数model方法
    Items items = d1.model(text);
    EXPECT_EQ(items[0], 3);
    EXPECT_EQ(items[1], 0);
    EXPECT_EQ(items[2], 0);
    EXPECT_EQ(items[3], 0);
    EXPECT_EQ(items[4], 0);
    EXPECT_EQ(items[5], 0);
}

TEST(BAYES_DOCUMENT, DOCUMENT_ITEMS)
{
    string text("I like football watching football matches every week occasionally playing football game");

    // 定义字典
    Dictionary dictionary = { "football", "match", "coldplay", "greenday", "java", "python" };
    
    // 设置Document的静态属性字典
    Document::set_dictionary(dictionary);
    Document d1(text);
    
    // 测试items方法
    Items items1 = d1.model(text);
    Items items2 = d1.items();

    EXPECT_EQ(items1[0], items2[0]);
    EXPECT_EQ(items1[1], items2[1]);
    EXPECT_EQ(items1[2], items2[2]);
    EXPECT_EQ(items1[3], items2[3]);
    EXPECT_EQ(items1[4], items2[4]);
    EXPECT_EQ(items1[5], items2[5]);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
