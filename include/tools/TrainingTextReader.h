//
// Date: 2015/09/21
//

#ifndef TOOLS_TRAININGTEXTREADER_H
#define TOOLS_TRAININGTEXTREADER_H

#include "TrainingData.h"

#include <string>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::string;

//
// TrainingTextReader类
// 读取待训练的文本数据
//
class TrainingTextReader
{
    public:
        TrainingTextReader(const string&, int);
        
        string read();
    private:
        void _load_training_data();

        string _path;
        TrainingData _trainingData;
        TrainingData::iterator _iter;
};
#endif
