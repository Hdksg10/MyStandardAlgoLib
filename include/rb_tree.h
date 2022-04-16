//
// Created by Rhywu on 2022/4/14.
//
//需要修改：删除操作
#ifndef MYSTANDARDALGOLIB_RB_TREE_H
#define MYSTANDARDALGOLIB_RB_TREE_H
#include "base.hpp"
namespace ctd {
    template<typename ElemT>
    struct rb_node{
        using typevalue = ElemT;
        using pointer = rb_node<ElemT>*;
        bool color;//0 = black, 1 = red
        pointer left;
        pointer right;
        pointer parent;
        typevalue key;
        rb_node(typevalue val ,pointer head_ptr, bool node_color);
        rb_node(pointer head_ptr, bool node_color);
    };

    template<typename ElemT>
    class rb_tree{
        friend class rb_node<ElemT>;
        using node =  rb_node<ElemT>;
        using typevalue = ElemT;
    private:

        ctd::rb_node<ElemT>*& _findParentPtr(node* curr);
        static rb_node<ElemT> NIL_NODE;
        static rb_node<ElemT>* NIL;
        void _delNode(node* root);
        void _insert_fix(node* curr);
        void _del_fix(node* curr);
        void _right_rotate(node* node);
        void _left_rotate(node* node);
        void _transplant(node* curr, node* target);
    public:
        node* _root;
        rb_tree();
        ~rb_tree();
        void temp_print();
        void print(node* roots);
        node* successor(node* node);
        node* insert(const typevalue& val);
        void remove(node* curr);
    };
    template<typename ElemT>
    rb_node<ElemT> rb_tree<ElemT>::NIL_NODE(NULL, false);
    template<typename ElemT>
    rb_node<ElemT>* rb_tree<ElemT>::NIL = &rb_tree<ElemT>::NIL_NODE;
}
#endif //MYSTANDARDALGOLIB_RB_TREE_H
