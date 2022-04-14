#include <iostream>
#include <vector>
#include "include/list.hpp"
#include "include/sort.hpp"
#include "include/forward_list.hpp"
#include "include/binary_search_tree.h"
#include "src/binary_search_tree.cpp"
using namespace ctd;

int main()
{

    binary_search_tree<int> bst;
    bst.insert(3);
    bst.insert(1);
    bst.insert(6);
    bst.insert(0);
    bst.insert(4);
    bst.insert(7);
    bst.insert(2);
    bst.remove(bst._root->left);

    bst.temp_print();

    return 0;
}

