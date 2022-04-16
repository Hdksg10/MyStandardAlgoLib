//
// Created by RhyWu on 2022/4/12.
//

#ifndef MYSTANDARDALGOLIB_BINARY_SEARCH_TREE_H
#define MYSTANDARDALGOLIB_BINARY_SEARCH_TREE_H
#include "base.hpp"
namespace ctd{
    template<typename ElemT>
    struct Nodes{
        using typevalue = ElemT;
        using pointer = Nodes<ElemT>*;
        typevalue key;
        pointer parent;
        pointer left;
        pointer right;
        Nodes(typevalue val, pointer head_ptr);

    };
    template<typename ElemT>
    class binary_search_tree{
        using typevalue = ElemT;
        using node = Nodes<typevalue>;
    private:
        node* _root;
        void _delNode(node* root);
        node* _successor(node* node);
        void _transplant(node* curr, node* target);
        ctd::Nodes<ElemT>*& _findParentPtr(node* curr);
    public:
        binary_search_tree();
        ~binary_search_tree();
        void temp_print();
        void print(node* roots);
        void insert(const typevalue& val);
        bool search(const typevalue& val)const;
        typevalue minimum()const;
        typevalue maximum()const;
        void remove(node* node);
    };
}

#endif //MYSTANDARDALGOLIB_BINARY_SEARCH_TREE_H
