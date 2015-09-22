//
// Date: 2015/09/21
//

#include "TrainingData.h"

using namespace std;

TrainingData::TrainingData(int cate_num):
    _categories(cate_num),
    _p_filenames(std::make_shared<FileNamesSetType>(_categories))
{
}

void TrainingData::add(int cate, const string& filename)
{
    (*_p_filenames).at(cate).insert(filename);
}

TrainingData::iterator TrainingData::begin()
{
    return _p_filenames->begin();
}

TrainingData::iterator TrainingData::end()
{
    return _p_filenames->end();
}
