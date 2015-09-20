//
// Date: 2015/09/21
//

#include "../include/bayes/Items.h"
#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(BAYES_ITEMS, ITEM)
{
    Item item1(vector<int>({0, 1, 2, 3, 4, 5}));
    
    EXPECT_EQ(item1.key, 0);
    EXPECT_EQ(item1.value, "item_test");
    
    Item<string, string> item2;
    
    item2.key = "hello";
    item2.value = "world";
    
    EXPECT_EQ(item2.key, "hello");
    EXPECT_EQ(item2.value, "world");
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
