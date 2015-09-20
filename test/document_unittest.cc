#include "../include/Item.h"
#include "../include/Document.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>

using namespace std;

TEST(BAYES_ITEM, ITEM)
{
    Document<int, int> doc1({ {1, 2}, {2, 3} });
    doc1.print(cout);
    
    //EXPECT_EQ(item1.key, 0);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
