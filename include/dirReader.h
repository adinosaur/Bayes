#ifndef TRAININGTEXTREADER_H
#define TRAININGTEXTREADER_H

#include <string>
#include <vector>
#include <map>

typedef std::map<int, std::vector<std::string> > Corpus;

void get_filenames_in_dir(std::vector<std::string>& v, std::string path);

class TrainingTextReader{
    public:
        TrainingTextReader(std::string path="training/"):_path(path){}
        void read();
        void print();
        Corpus& get_corpus();
    private:
        std::string _path;
        Corpus _text_corpus;
};
#endif
