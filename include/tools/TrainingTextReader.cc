//
// Date: 2015/09/21
//

#include "trainingTextReader.h"
#include "trainingData.h"

#include <dirent.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//
// 读一个目录，返回该目录下的所有文件名
//
vector<string> Readdir(const string& path)
{
    // 返回一个vector，但是由于编译器会优化因此不会进行多余的拷贝
    vector<string> filenames;
    
    struct dirent* ptr;
    DIR* dir = opendir(path.c_str());
    
    while ((ptr = readdir(dir)) != NULL)
        if (ptr->d_name[0] != '.')
            filenames.push_back(ptr->d_name);

    return filenames;
}

//
// 读目录，返回目录下的所有目录文件的文件名
//
vector<string> Readdir2(const string& path)
{
    vector<string> filenames;

    struct dirent* ptr;
    DIR* dir = opendir(path.c_str());

    while ((ptr = readdir(dir)) != NULL)
        if (ptr->d_name[0] != '.' && ptr->d_type != DT_DIR)
            filenames.push_back(ptr->d_name);

    return filenames;
}

//
// 构造函数
// 指定training数据的目录和类别的大小
//
TrainingTextReader::TrainingTextReader(const string& path, int cate_num):
    _path(path),
    _trainingData(TrainingData(cate_num)),
    _iter(_trainingData.begin())
{
    _load_training_data();
}

void TrainingTextReader::_load_training_data()
{
    vector<string> dirs = Readdir2(_path);
    
    for (vector<string>::size_type i = 0; i != dirs.size(); ++i)
    {
        string dir_path(path + "/" + dirs[i]);
        vector<string> filenames_vec = Readdir(dir_path);

        // c++11 lambda
        for_each(filenames_vec.begin(), filenames_vec.end(), 
            [&_trainingData, i, dir_path] (string&& s)
            {
                _trainingData.add(i, dir_path + s);
            }
        );
    }
}

string TrainingTextReader::read()
{
    if (_iter == _trainingData.end())
        return string("");
    
    
    vector<string> classnames;
    get_filenames_in_dir(classnames, _path);
    for (vector<string>::iterator it = classnames.begin(); it != classnames.end(); ++it)
    {
        vector<string> filenames, corpus;
        
        string c = _path + *it;
        //cout << c << endl;
        get_filenames_in_dir(filenames, c); 
        for (vector<string>::iterator it2 = filenames.begin(); it2 != filenames.end(); ++it2)
        {
            ifstream in((_path + (*it) + '/' + (*it2)).c_str());
            string text;
            while (in >> text)
                corpus.push_back(text);
            in.close();
        }
        _text_corpus[atoi(it->c_str())] = corpus;
    }
}
