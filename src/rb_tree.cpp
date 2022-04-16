//
// Created by Rhywu on 2022/4/15.
//
#include "../include/rb_tree.h"
/**
 * 红黑树节点构造函数
 * @tparam ElemT
 * @param val
 * @param head_ptr
 * @param node_color
 */
template<typename ElemT>
ctd::rb_node<ElemT>::rb_node(typevalue val, pointer head_ptr, bool node_color): key(val), parent(head_ptr), color(node_color)
                                                                                , left(ctd::rb_tree<ElemT>::NIL)
                                                                                , right(ctd::rb_tree<ElemT>::NIL) {}
/**
 *
 * @tparam ElemT
 * @param head_ptr
 * @param node_color
 */
template<typename ElemT>
ctd::rb_node<ElemT>::rb_node(pointer head_ptr, bool node_color): parent(head_ptr), color(node_color)
                                                                 , left(ctd::rb_tree<ElemT>::NIL)
                                                                 , right(ctd::rb_tree<ElemT>::NIL) {}
/**
 *
 * @tparam ElemT
 */
template<typename ElemT>
ctd::rb_tree<ElemT>::rb_tree() {
    _root = NIL;
}
/**
 * 析构函数，递归删除所有节点
 * @tparam ElemT
 */
template<typename ElemT>
ctd::rb_tree<ElemT>::~rb_tree() {
    _delNode(_root);
}
/**
 * 递归删除BST所有节点的递归部分
 * @tparam ElemT:节点值的类型
 * @param root: 默认为根节点
 */
template<typename ELemT>
void ctd::rb_tree<ELemT>::_delNode(node *root)
{
    if(root != NIL)
    {
        _delNode(root->left);
        _delNode(root->right);
        delete root;
    }
}

/**
 *
 * @tparam ElemT
 * @param node
 */
template<typename ElemT>
void ctd::rb_tree<ElemT>::_left_rotate(node *node)
{
    auto node_parent = node->parent;
    node_parent->right = node->left;
    if(node->left != NIL)
        node->left->parent = node_parent;
    _findParentPtr(node_parent) = node;
    node->parent = node_parent->parent;
    node->left = node_parent;
    node_parent->parent = node;
}

template<typename ElemT>
void ctd::rb_tree<ElemT>::_right_rotate(node *node)
{
    auto node_parent = node->parent;
    node_parent->left = node->right;
    if(node->right != NIL)
        node->right->parent = node_parent;
    _findParentPtr(node_parent) = node;
    node->parent = node_parent->parent;
    node->right = node_parent;
    node_parent->parent = node;
}
/**
 * 用于寻找某个节点的双亲指向其的指针
 * @tparam ElemT 节点值的类型
 * @param curr 待寻找的节点
 * @return 返回该节点的双亲指向其的指针(parent->left/right 的引用)
 */
template<typename ElemT>
ctd::rb_node<ElemT>*& ctd::rb_tree<ElemT>::_findParentPtr(node* curr)
{
    if(curr->parent == NIL)
        return _root;
    else if(curr->parent->left == curr)
    {
        return curr->parent->left;
    }
    else if(curr->parent->right == curr)
    {
        return curr->parent->right;
    }
}
template<typename ElemT>
void ctd::rb_tree<ElemT>::_insert_fix(node *curr)
{
    auto node_parent = curr->parent;
    if(node_parent->color == false)
    {
        if(_root == curr)
            curr->color = false;
        return;
    }
    else if(node_parent->parent->left == node_parent)
    {
        if(node_parent->parent->right->color == true)
        {
            node_parent->color = false;
            node_parent->parent->color = true;
            node_parent->parent->right->color = false;
            _insert_fix(node_parent->parent);
        }
        else if(node_parent->parent->right->color ==false && curr == node_parent->left)
        {
            node_parent->color = false;
            node_parent->parent->color = true;
            _right_rotate(node_parent);
        }
        else
        {
            _left_rotate(curr);
            _insert_fix(curr);
        }
    }
    else if(node_parent->parent->right == node_parent)
    {
        if(node_parent->parent->left->color == true)
        {
            node_parent->color = false;
            node_parent->parent->color = true;
            node_parent->parent->left->color = false;
            _insert_fix(node_parent->parent);
        }
        else if(node_parent->parent->left->color ==false && curr == node_parent->right)
        {
            node_parent->color = false;
            node_parent->parent->color = true;
            _left_rotate(node_parent);
        }
        else
        {
            _right_rotate(curr);
            _insert_fix(curr);
        }
    }
}
template<typename ElemT>
ctd::rb_node<ElemT>* ctd::rb_tree<ElemT>::insert(const typevalue &val)
{
    node* curr = _root;
    node* prev = NIL;
    while(curr!=NIL)
    {
        if(curr->key < val) {
            prev = curr;
            curr = curr->right;
        }
        else {
            prev = curr;
            curr = curr->left;
        }
    }
    curr = new node(val, prev, true);
    if (prev!=NIL) {
        if (prev->key < val)
            prev->right = curr;
        else
            prev->left = curr;
    }
    else
    {
        _root = curr;
    }
    _insert_fix(curr);
    return curr;
}
template<typename ElemT>
ctd::rb_node<ElemT>* ctd::rb_tree<ElemT>::successor(node *node)
{
    if(node -> right){
        node = node->right;
        while(node->left)
        {
            node = node->left;
        }
        return node;
    }
    else{
        while(node->parent && node->parent->left != node){
            node = node->parent;
        }
        return node->parent;
    }
}
template<typename ElemT>
void ctd::rb_tree<ElemT>::_transplant(node* curr, node* target)
{
    if(curr == target)
        return;
    else
    {
        if(target->parent == NIL)
        {
            _root = curr;
            curr->parent = NIL;
        }

        else
        {
            _findParentPtr(target) = curr;
            curr->parent = target->parent;
        }
    }
}
template<typename ElemT>
void ctd::rb_tree<ElemT>::remove(node *curr)
{
    if(curr->right == NIL && curr->left == NIL)
    {
        if(curr->color)
        {
            delete curr;
        }
        else
        {
            _del_fix(curr);
        }
    }
    else if(curr->left == NIL)
    {
        auto successor_node = curr->right;
        _findParentPtr(curr) = curr->right;
        curr->right->parent = curr->parent;
        delete curr;
        _del_fix(successor_node);
    }
    else if(curr->right == NIL)
    {
        auto successor_node = curr->left;
        _findParentPtr(curr) = curr->left;
        curr->left->parent = curr->parent;
        delete curr;
        _del_fix(successor_node);
    }
    else
    {
        auto successor_node = successor(curr);
        auto temp = successor_node->parent->left;
        _transplant(successor_node, curr);
        if(successor_node == curr->right)
        {
            successor_node->left = temp;
        }
        else
        {
            successor_node->left = curr->left;
            curr->left->parent = successor_node;
            auto position = successor_node;
            while (position->right) {
                position = position->right;
            }
            position->right = curr->right;
            curr->right->parent = position;
        }
        delete curr;
        _del_fix(successor_node);
    }
}

/**
 * @deprecated 开发时的测试函数,不要使用！
 * @tparam ElemT
 */
template<typename ElemT>
[[deprecated]] void ctd::rb_tree<ElemT>::temp_print() {
    print(_root);
}
/**
 * @deprecated 开发时的测试函数,不要使用！
 * @tparam ElemT
 */
template<typename ElemT>
[[deprecated]] void ctd::rb_tree<ElemT>::print(node* roots) {
    if(roots != NIL)
    {
        print(roots->left);
        printf("%d", roots->key);
        print(roots->right);
    }
}