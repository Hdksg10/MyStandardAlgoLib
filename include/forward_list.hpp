//
// Created by Rhywu on 2022/4/7.
//
//需要后续修改的地方：迭代器类与自身的几个拷贝构造，移动构造函数，赋值运算符之类的
#ifndef MYSTANDARDALGOLIB_FORWARD_LIST_HPP
#define MYSTANDARDALGOLIB_FORWARD_LIST_HPP
#include "base.hpp"
namespace ctd {

    template<typename ElemT>
    class forward_list {

    private:
        size_t size;

        struct Nodes {
            ElemT content;
            Nodes *next;

            explicit Nodes(Nodes *ptr) : next(ptr) {}

            Nodes(ElemT val, Nodes *ptr) : content(val), next(ptr) {}
        };

        Nodes *head;
        Nodes *tail;
    public:
        using valuetype = ElemT;

        class iterator {
            Nodes *pos;
        public:
            explicit iterator(Nodes *position) : pos(position) {}

            valuetype operator*() {
                return pos->content;
            }

            Nodes *operator++() {
                pos = pos->next;
                return pos;
            }

            Nodes *operator++(int) {
                Nodes *temp = pos;
                pos = pos->next;
                return temp;
            }

            iterator &operator=(iterator iter) {
                pos = iter.pos;
                return *this;
            }

            bool operator==(iterator iter) {
                return pos == iter.pos;
            }

            bool operator!=(iterator iter) {
                return pos != iter.pos;
            }

        };

        forward_list() {
            size = 0;
            head = new Nodes(nullptr);
            tail = head->next;
        }

        ~forward_list() {
            Nodes *current = head->next;
            Nodes *prev = head;
            while (current) {
                delete prev;
                prev = current;
                current = current->next;
            }
            delete prev;
        }

        void push_front(const ElemT &val) {
            size++;
            auto item = new Nodes(val, head->next);
            head->next = item;
            tail = size == 1 ? item->next : tail;
        }

        void pop_front() {
            if (head->next) {
                auto temp = head->next;
                head->next = head->next->next;
                delete temp;
            }
            tail = size == 0 ? nullptr : tail;
        }

        bool empty() {
            return size == 0;
        }

        ElemT front() {
            return head->next->content;
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator(tail);
        }

    };
}
#endif //MYSTANDARDALGOLIB_FORWARD_LIST_HPP
