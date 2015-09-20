//
// Date: 2015/09/21
//

#include "../include/bayes/Items.h"
#include "gtest/gtest.h"
#include <string>
#include <vector>

using namespace std;

TEST(BAYES_ITEMS, ITEM)
{
    Items items(vector<int>({0, 1, 2, 3, 4, 5, 7}));
    
    // 测试size函数
    EXPECT_EQ(items.size(), 7);
    
    // 测试下标operator[]函数
    EXPECT_EQ(items[0], 0);
    EXPECT_EQ(items[1], 1);
    EXPECT_EQ(items[2], 2);
    EXPECT_EQ(items[3], 3);
    EXPECT_EQ(items[4], 4);
    EXPECT_EQ(items[5], 5);
    EXPECT_EQ(items[6], 7);
    
    // 测试begin迭代器，end迭代器
    vector<int>::iterator beg = items.begin();
    //vector<int>::iterator end = items.end();
    
    EXPECT_EQ(*beg++, 0);
    EXPECT_EQ(*beg++, 1);
    EXPECT_EQ(*beg++, 2);
    EXPECT_EQ(*beg++, 3);
    EXPECT_EQ(*beg++, 4);
    EXPECT_EQ(*beg++, 5);
    EXPECT_EQ(*beg++, 7);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
