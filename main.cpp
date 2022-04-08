#include <iostream>
#include <vector>
#include "include/sort.hpp"
#include "include/forward_list.hpp"

int main()
{
    forward_list<int> linkedlist;
    linkedlist.push_front(3);
    linkedlist.push_front(5);
    auto st = linkedlist.begin();
    auto lt = linkedlist.end();
    linkedlist.pop_front();
    linkedlist.push_front(23);
    linkedlist.pop_front();
    linkedlist.pop_front();
    while(st != lt)
    {
        std::cout<<*st<<std::endl;
        ++st;
    }
    return 0;
}
