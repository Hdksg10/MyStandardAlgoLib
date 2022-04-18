#include <iostream>
#include <vector>
#include "include/list.hpp"
#include "include/sort.hpp"
#include "include/forward_list.hpp"
#include "include/binary_search_tree.h"
#include "include/rb_tree.h"
using namespace ctd;

int main()
{

    std::vector<int> rs{3,5,1,6,-2,0,12,12,-4,-2,3,0,9};
    quicksort(rs.begin(), rs.end());
    for(auto i : rs)
    {
        std::cout<<i<<" ";
    }
//    for(int i = 0; i <100; i++)
//        std::cout<<ctd::random_int(1,12)<<" ";
    //std::cout<<ctd::distance(rs.begin(), rs.end());
    return 0;
}

