#include "myJieba.h"

MyJieba::MyJieba()
{
    p_app = new CppJieba::Application(
        "cppjieba/dict/jieba.dict.utf8",
        "cppjieba/dict/hmm_model.utf8",
        "cppjieba/dict/user.dict.utf8",
        "cppjieba/dict/idf.utf8",
        "cppjieba/dict/stop_words.utf8"
    );
}

MyJieba::~MyJieba()
{
    delete p_app;
}

void MyJieba::cut(std::vector<std::string> &words, std::string s)
{
    p_app->cut(s, words);
}
