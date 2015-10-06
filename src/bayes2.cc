#include "../include/bayes/Items.h"
#include "../include/bayes/Dictionary.h"
#include "../include/bayes/Document.h"
#include "../include/bayes/Training.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
    // 定义待分类的类别数
    int category = 3;

    // 定义用于分类的字典
    Dictionary dictionary = { "football", "match", "coldplay", "greenday", "java", "python" };
    Document::set_dictionary(dictionary);

    // 创建Document对象
    Document d1("I like football watching football matches every week occasionally playing football game");
    Document d2("My favorite band is coldplay and greenday I really like the viva la vida ");
    Document d3("i often use java but in fact i dont like java at not i like python because life is short i use python");
    Document d4("in my opinion coldplay is more famous than greenday although i also like greenday");
    Document d5("what is java i only use python python is easy");
    Document d6("which is better java or python");

    // 定义Training对象
    Training t(category, dictionary.size());

    // 添加训练数据，监督式训练
    t.add_document(d1, 0);
    t.add_document(d2, 1);
    t.add_document(d3, 2);
    t.add_document(d4, 1);
    t.add_document(d5, 2);

    t.training();

    // 通过朴素贝叶斯分类器对Document进行分类
    auto result = t.bayes(d6);

    // 输出贝叶斯分类结果
    cout << "bayes classification: " << endl;
    for (int i = 0; i != result.size(); ++i)
    {
        cout << i << ": " << result[i] << endl;
    }
    return 0;
}
