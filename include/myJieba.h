#ifndef MYJIEBA_H
#define MYJIEBA_H

#include "cppjieba/src/Application.hpp"
using namespace CppJieba;

class MyJieba {
public:
    MyJieba();
    ~MyJieba();
    void cut(std::vector<std::string> &words, std::string s);
private:
    CppJieba::Application* p_app;
};
#endif
