#include "../include/Item.h"
#include "../include/Dictionary.h"
#include "../include/Document.h"
#include "../include/Training.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
    int category = 3;
    int dimension = 6;

    Dictionary<string> dictionary = { "football", "match", "coldplay", "greenday", "java", "python" };

    Document d1 = { 2, 3, 0, 1, 0, 0 };
    Document d2 = { 0, 1, 4, 2, 0, 0 };
    Document d3 = { 0, 2, 0, 0, 5, 1 };
    Document d4 = { 0, 0, 1, 3, 0, 0 };
    Document d5 = { 0, 1, 0, 0, 3, 4 };
    
    for (auto  x : d1.translate(&dictionary))
        cout << "(" << x.key << "," << x.value << "), ";
    cout << endl;
    
    Document d6 = {1, 3, 0, 0, 2, 5};

    Training t(category, dimension);
    
    t.add_document(d1, 0);
    t.add_document(d2, 1);
    t.add_document(d3, 2);
    t.add_document(d4, 1);
    t.add_document(d5, 2);
    
    auto doc_cate_d = t.document_category_distribution();
    auto item_cate_d = t.item_category_distribution();
    
    cout << "document category distribution: " << endl;
    for (int i = 0; i != doc_cate_d.size(); ++i)
    {
        cout << i << ": " << doc_cate_d[i] << endl;
    }

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
    
    auto result = t.bayes(d6);
    cout << "bayes classification: " << endl;
    for (int i = 0; i != result.size(); ++i)
    {
        cout << i << ": " << result[i] << endl;
    }
    return 0;
}
