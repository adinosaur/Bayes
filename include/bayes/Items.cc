//
// Date: 2015/09/20
//

#include "Items.h"

#include <memory>
#include <vector>

using namespace std;

Items::Items(const vector<int>& items)
{
    _p_items = make_shared<vector<int>>(items);
}

Items::Items(vector<int>&& items)
{
    _p_items = make_shared<vector<int>>(std::move(items));
}

Items::Items(std::initializer_list<int>&& lst):
    _p_items(make_shared<vector<int>>())
{
    for (auto&& item : lst)
        _p_items->push_back(std::move(item));
}

int Items::size()
{
    return _p_items->size();
}

int Items::operator[](int i)
{
    return _p_items->at(i);
}

vector<int>::iterator Items::begin()
{
    return _p_items->begin();
}

vector<int>::iterator Items::end()
{
    return _p_items->end();
}
