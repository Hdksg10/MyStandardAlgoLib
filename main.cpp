#include <iostream>
#include <vector>
#include "include/list.hpp"
#include "include/sort.hpp"
#include "include/forward_list.hpp"
#include "include/binary_search_tree.h"
#include "src/binary_search_tree.cpp"
#include "include/rb_tree.h"
#include "src/rb_tree.cpp"
using namespace ctd;

int main()
{

    std::vector<int> rs{5,4,3,2,1};
    auto st = std::begin(rs);
    auto ed = std::end(rs);
    mergesort(st, ed);
    for(auto i : rs)
    {
        std::cout<<i;
    }
    return 0;
}

