#include "dirReader.h"
#include <dirent.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

/*  函数定义
 *  参数：向量v调用完成后将保存目录path下的所有文件名（不包括.和..）
 * 
 */
void get_filenames_in_dir(vector<string>& v, string path)
{
    struct dirent* ptr;
    DIR* dir = opendir(path.c_str());
    while ((ptr = readdir(dir)) != NULL)
    {
        if (ptr->d_name[0] != '.')
            v.push_back(string(ptr->d_name));
    }
}

/*  TrainingTextReader成员函数
 *  读取目录_path下的所有训练文件，_path中的每个子目录是一个类别，子目录中是该分类的训练数据
 *
 */
void TrainingTextReader::read()
{
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

/*  TrainingTextReader成员函数
 *  打印读取进内存的文本数据
 *
 */
void TrainingTextReader::print()
{
    for (map<int, vector<string> >::iterator it = _text_corpus.begin(); it != _text_corpus.end(); ++it)
    {
        cout << it->first << endl;
        for (vector<string>::iterator it2 = (it->second).begin(); it2 != (it->second).end(); ++it2)
        cout << *it2 << endl;
    }
}

/*  TrainingTextReader成员函数
 *  返回 _text_corpus的引用
 *
 */
Corpus& TrainingTextReader::get_corpus()
{
    return _text_corpus;
}
