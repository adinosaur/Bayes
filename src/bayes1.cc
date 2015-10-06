//
// Date: 2015/10/06
//
// 这里详细地演示了如何通过Bayes库对文档进行分类。
//
// 朴素Bayes基于条件概率和条件独立性假设，通过统计先验概率分布和对文档词频计算出后验概率
// 对一篇文本分类的步骤大致为以下几步：
//      (1) 对文本建模(modeling)，用一个向量来表示一篇文本。这里使用的是词袋模型。
//      (2) 统计每类型的文档出现的概率，即是先验概率。
//      (3) 统计向量的每一个维度在每种类型文章出现的频率。
//      (4) 分类。对每一个待分类的向量根据条件概率公式求得最大概率的类别。
//
// Bayes训练会得出两个值：
//      1. doc_cate_d
//      2. item_cate_d
//
// L57: doc_cate_d是一个向量，记录这文档的概率（先验概率）
// L60: item_cate_d是一个2维的矩阵，记录每一种类型的文档的词频向量。

#include "../include/bayes/Items.h"
#include "../include/bayes/Dictionary.h"
#include "../include/bayes/Document.h"
#include "../include/bayes/Training.h"
#include "../include/bayes/Modeling.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
    // 定义待分类的类别数
    int category = 3;

    // 定义用于分类的字典
    Dictionary dictionary = { "football", "match", "coldplay", "greenday", "java", "python" };

    // 使用简单的词袋模型
    Document<string>::set_modeling(WordBagModel(&dictionary));

    // 创建Document对象
    Document<string> d1("I like football watching football matches every week occasionally playing football game");
    Document<string> d2("My favorite band is coldplay and greenday I really like the viva la vida ");
    Document<string> d3("i often use java but in fact i dont like java at not i like python because life is short i use python");
    Document<string> d4("in my opinion coldplay is more famous than greenday although i also like greenday");
    Document<string> d5("what is java i only use python python is easy");
    Document<string> d6("which is better java or python");

    // 定义Training对象
    Training<string> t(category, dictionary.size());

    // 添加训练数据，监督式训练
    t.add_document(d1, 0);
    t.add_document(d2, 1);
    t.add_document(d3, 2);
    t.add_document(d4, 1);
    t.add_document(d5, 2);

    // 训练得出 Document-类别 概率分布
    auto doc_cate_d = t.document_category_distribution();
    
    // 训练得出 Item-类别 概率分布
    auto item_cate_d = t.item_category_distribution();

    // 输出 Document-类别 概率分布
    cout << "document category distribution: " << endl;
    for (int i = 0; i != doc_cate_d.size(); ++i)
    {
        cout << i << ": " << doc_cate_d[i] << endl;
    }

    // 输出 Item-类别 概率分布
    cout << "item category distribution: " << endl;
    for (int i = 0; i != item_cate_d.size(); ++i)
    {
        cout << i << ": ";
        for(int j = 0; j != item_cate_d[i].size(); ++j)
        {
            cout << "(" << j << "," << item_cate_d[i][j] << "), ";
        }
        cout << endl;
    }
    
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
