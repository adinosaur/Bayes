#include <iostream>
#include <vector>
#include <string>
#include "dirReader.h"
#include "myJieba.h"

using namespace std;

int main(int ac, char** av)
{
    TrainingTextReader t;
    t.read();
    //t.print();
    
    vector<string> words; 
    MyJieba myjieba;
    myjieba.cut(words, (t.get_corpus())[0][0]);
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
        cout << *it << endl;
    return 0;
}
