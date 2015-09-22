//
// Date: 2015/09/21
//

#include "../include/tools/TrainingData.h"

#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST(BAYES_TOOLS_TRAININGDATA, TRAININGDATA)
{
    TrainingData trainingData(3);
    
    string filename1("football.news");
    string filename2("programming.news");
    string filename3("coldplay-music");
    string filename4("python-skill");
    string filename5("greenday-band");
    
    trainingData.add(0, filename1);
    trainingData.add(1, filename2);
    trainingData.add(2, filename3);
    trainingData.add(1, filename4);
    trainingData.add(2, filename5);
    
    // 测试begin迭代器，end迭代器
    TrainingData::iterator beg = trainingData.begin();
    TrainingData::iterator end = trainingData.end();
    
    for (; beg != end; ++beg)
    {
        cout << "[";
        for (auto x : *beg)
            cout << x << " ";
        cout << "]" << endl;
    }
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
