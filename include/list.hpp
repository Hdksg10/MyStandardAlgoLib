//
// Created by Rhywu on 2022/4/10.
//

#ifndef MYSTANDARDALGOLIB_LIST_HPP
#define MYSTANDARDALGOLIB_LIST_HPP
#include "base.hpp"
namespace ctd {
    template<typename ElemT>
    struct list_node {
        list_node *prev = nullptr;
        list_node *next = nullptr;
        ElemT value;

        list_node(ElemT val, list_node *prev_ptr, list_node *next_ptr) : prev(prev_ptr), next(next_ptr), value(val) {}

        list_node(list_node *prev_ptr, list_node *next_ptr) : prev(prev_ptr), next(next_ptr) {}
    };


    template<typename ElemT>
    class list_iterator {
        using Node = list_node<ElemT>;
    private:
        Node *pos;

    public:
        explicit list_iterator(Node *position) {
            pos = position;
        }

        list_iterator operator++() {
            pos = pos->next;
            return *this;
        }

        list_iterator operator++(int) {
            Node *temp = pos;
            pos = pos->next;
            return list_iterator(temp);
        }

        list_iterator operator--() {
            pos = pos->prev;
            return *this;
        }

        list_iterator operator--(int) {
            Node *temp = pos;
            pos = pos->prev;
            return list_iterator(temp);
        }

        ElemT operator*() {
            return pos->value;
        }

        bool operator==(list_iterator iter) {
            return pos == iter.pos;
        }

        bool operator!=(list_iterator iter) {
            return pos != iter.pos;
        }
    };


    template<typename ElemT>
    class list {
        using Node = list_node<ElemT>;
        using iterator = list_iterator<ElemT>;
        using typevalue = ElemT;

        friend class list_iterator<ElemT>;

    private:
        size_t _size;
        Node *head;
    public:

        list() {
            head = new Node(nullptr, nullptr);
            head->prev = head;
            head->next = head;
            _size = 0;
        }

        ~list() {
            Node *curr = head->next;
            while (curr != head) {
                curr = curr->next;
                delete curr->prev;
            }
            delete curr;
        }


        void pop_back() {
            if (head->prev != head) {
                Node *temp = head->prev;
                head->prev->prev->next = head;
                head->prev = head->prev->prev;
                delete temp;
                _size--;

            } else
                return;
        }

        void pop_front() {
            if (head->next != head) {
                Node *temp = head->next;
                head->next->next->prev = head;
                head->next = head->next->next;
                delete temp;
                _size--;
            }
        }

        void push_back(const typevalue &val) {
            if (empty()) {
                Node *node = new Node(val, head, head);
                head->next = node;
                head->prev = node;
            } else {
                Node *node = new Node(val, head->prev, head);
                head->prev->next = node;
                head->prev = node;
            }
        }

        void push_front(const typevalue &val) {
            if (empty()) {
                Node *node = new Node(val, head, head);
                head->next = node;
                head->prev = node;
            } else {
                Node *node = new Node(val, head, head->next);
                head->next->prev = node;
                head->next = node;
            }
        }

        bool empty() {
            return head->next == head;
        }

        typevalue front() {
            return head->next->value;
        }

        typevalue back() {
            return head->prev->value;
        }

        size_t size() {
            return _size;
        }

        iterator begin() {
            return list_iterator(head->next);
        }

        iterator end() {
            return list_iterator(head);
        }


    };
}
#endif //MYSTANDARDALGOLIB_LIST_HPP
