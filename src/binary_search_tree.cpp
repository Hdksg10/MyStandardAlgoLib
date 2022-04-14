//
// Created by RhyWu on 2022/4/12.
//
#include "../include/binary_search_tree.h"
/**
 * 树节点的构造函数
 * @tparam ElemT:节点值的类型
 * @param val:新节点的值 @param head_ptr:新节点的头结点
 */
template<typename ElemT>
ctd::Nodes<ElemT>::Nodes(typevalue val, pointer head_ptr) : key (val), parent(head_ptr), left(nullptr), right(nullptr) {}
/**
 * 递归删除BST所有节点的递归部分
 * @tparam ElemT:节点值的类型
 * @param root: 默认为根节点
 */
template<typename ElemT>
void ctd::binary_search_tree<ElemT>::_delNode(Nodes<typevalue> *root)
{
    if(root)
    {
        _delNode(root->left);
        _delNode(root->right);
        delete root;
    }
}
/**
 * BST的析构函数，递归删除所有节点
 * @tparam ElemT:节点值的类型
 */
template<typename ElemT>
ctd::binary_search_tree<ElemT>::~binary_search_tree()
{
    _delNode(_root);
}

/**
 * 在BST中查找是否存在指定值的节点（不保证唯一）
 * @tparam ElemT:节点值的类型
 * @param val:待查找的值
 * @return bool:存在为True, 不存在为False
 */
template<typename ElemT>
bool ctd::binary_search_tree<ElemT>::search(const typevalue &val) const
{
    node* curr = _root;
    while(curr)
    {
        if(curr->key==val)
            return true;
        else if(curr->key < val)
            curr = curr->right;
        else
            curr = curr->left;
    }
    return false;
}

/**
 * 向BST中插入新元素
 * @tparam ElemT:节点值的类型
 * @param val:新节点的值
 */
template<typename ElemT>
void ctd::binary_search_tree<ElemT>::insert(const typevalue &val)
{
    node* curr = _root;
    node* prev = nullptr;
    while(curr)
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
    curr = new node(val, prev);
    if (prev) {
        if (prev->key < val)
            prev->right = curr;
        else
            prev->left = curr;
    }
    else
        _root = curr;
}
/**
 * 构造函数
 * @tparam ElemT :节点值的类型
 */
template<typename ElemT>
ctd::binary_search_tree<ElemT>::binary_search_tree()
{
    _root = nullptr;
}
/**
 * 查找并返回BST中最小值
 * @tparam ElemT :节点值的类型
 * @return ElemT:最小值,空树时无返回
 */
template<typename ElemT>
ElemT ctd::binary_search_tree<ElemT>::minimum() const
{
    node* curr = _root;
    while(curr->left)
        curr = curr->left;
    if(curr)
        return curr->key;

}
/**
 * 查找并返回BST中最大值
 * @tparam ElemT :节点值的类型
 * @return ElemT:最大值,空树时无返回
 */
template<typename ElemT>
ElemT ctd::binary_search_tree<ElemT>::maximum() const
{
    node* curr = _root;
    while(curr->right)
        curr = curr->right;
    if(curr)
        return curr->key;

}
/**
 * @deprecated 开发时的测试函数,不要使用！
 * @tparam ElemT
 */
template<typename ElemT>
[[deprecated]] void ctd::binary_search_tree<ElemT>::temp_print() {
    print(_root);
}
/**
 * @deprecated 开发时的测试函数,不要使用！
 * @tparam ElemT
 */
template<typename ElemT>
[[deprecated]] void ctd::binary_search_tree<ElemT>::print(Nodes<typevalue>* roots) {
    if(roots)
    {
        print(roots->left);
        printf("%d", roots->key);
        print(roots->right);
    }

}
/**
 * 寻找某个节点的后继，用于删除某个节点
 * @tparam ElemT :节点值的类型
 * @param node :要寻找后继的节点
 * @return 返回指向该节点后继的指针
 */
template<typename ElemT>
ctd::Nodes<ElemT>* ctd::binary_search_tree<ElemT>::_successor(Nodes<typevalue> *node) {
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
/**
 * 将某个节点移动到另一个节点的位置上，不对节点的子节点做任何处理，用于删除节点
 *
 * @tparam ElemT :节点值的类型
 * @param curr :待移动的节点
 * @param target :移动到的目标节点
 */
template<typename ElemT>
void ctd::binary_search_tree<ElemT>::_transplant(node* curr, node* target)
{
    if(curr == target)
        return;
    else
    {
        if(target->parent == nullptr)
        {
            _root = curr;
            curr->parent = nullptr;
        }

        else
        {
            _findParentPtr(target) = curr;
            curr->parent = target->parent;
        }
    }
}
/**
 * 用于寻找某个节点的双亲指向其的指针
 * @tparam ElemT 节点值的类型
 * @param curr 待寻找的节点
 * @return 返回该节点的双亲指向其的指针(parent->right 的引用)
 */
template<typename ElemT>
ctd::Nodes<ElemT>*& ctd::binary_search_tree<ElemT>::_findParentPtr(node *curr)//curr is not the root
{
    if(curr->parent->left == curr)
    {
        return curr->parent->left;
    }
    else if(curr->parent->right == curr)
    {
        return curr->parent->right;
    }
}
/**
 * 从BST中删除某个节点
 * @tparam ElemT 节点值的类型
 * @param node 指向该节点的指针
 */
template<typename ElemT>
void ctd::binary_search_tree<ElemT>::remove(node* node)
{
    if(node->left == nullptr && node->right == nullptr)
    {
        _findParentPtr(node) = nullptr;
        delete node;

    }
    else if(node->right == nullptr)
    {
        _transplant(node->left, node);
        delete node;
    }
    else if(node->left == nullptr)
    {
        _transplant(node->right, node);
        delete node;
    }
    else
    {
        auto successor = _successor(node);
        auto temp = successor->parent->left;
        successor->parent->left = nullptr;
        if(successor == node->right)
        {
            _transplant(successor, node);
            successor->left = temp;
        }
        else
        {
            _transplant(successor, node);
            successor->left = node->left;
            node->left->parent = successor;
            auto position = successor;
            while (position->right) {
                position = position->right;
            }
            position->right = node->right;
            node->right->parent = position;
        }
        delete node;
    }
}