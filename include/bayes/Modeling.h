//
// Date: 2015/10/06
//

#include "Items.h"
//#include "Dictionary.h"
#include <vector>

using namespace std;

class Dictionary;

//
// 每一个Modeling类应该实现的将某一类型的对象转换成一个Items向量
//

//
// 简单词袋模型
//
class WordBagModel
{
    public:
        explicit WordBagModel(Dictionary* p_dictionary);
        Items operator()(const string& text);

    private:
        Dictionary* _p_dictionary;
};

