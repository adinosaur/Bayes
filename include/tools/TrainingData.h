//
// Date: 2015/09/21
//

#ifndef TOOLS_TRAININGDATA_H
#define TOOLS_TRAININGDATA_H

#include <string>
#include <vector>
#include <memory>
#include <set>

using std::string;
using std::vector;
using std::shared_ptr;
using std::set;

class TrainingData
{
    public:
        typedef vector<set<string>> FileNamesSetType;
        typedef FileNamesSetType::iterator iterator;

        explicit TrainingData(int);
        //TrainingData(vector<set<string>>&);

        void add(int, const string&);

        iterator begin();
        iterator end();
        
    private:
        int _categories;
        shared_ptr<FileNamesSetType> _p_filenames;
};

#endif
