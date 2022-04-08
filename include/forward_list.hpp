//
// Created by Rhywu on 2022/4/7.
//

#ifndef MYSTANDARDALGOLIB_FORWARD_LIST_HPP
#define MYSTANDARDALGOLIB_FORWARD_LIST_HPP

template<typename ElemT>
class forward_list
{

private:
    int size;
    struct Nodes
    {
        ElemT content;
        Nodes* next;
        explicit Nodes(Nodes* ptr):next(ptr){}
        Nodes(ElemT val, Nodes* ptr):content(val), next(ptr){}
    };
    Nodes* head;
    Nodes* tail;
public:
    using valuetype = ElemT;
    class iterator
    {
        Nodes* pos                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ;
    public:
        explicit iterator(Nodes* position) : pos(position){}
        valuetype operator*()
        {
            return pos->content;
        }

        void operator++()
        {
            pos = pos->next;
        }

        bool operator==(iterator iter)
        {
            return pos == iter.pos;
        }

        bool operator!=(iterator iter)
        {
            return pos != iter.pos;
        }

    };
    forward_list()
    {
        size = 0;
        head = new Nodes(nullptr);
        tail = head->next;
    }

    ~forward_list()
    {
        Nodes* current = head->next;
        Nodes* prev = head;
        while (current) {
            delete prev;
            prev = current;
            current = current->next;
        }
        delete prev;
    }

    void push_front(const ElemT& val)
    {
        size++;
        auto item = new Nodes(val, head->next);
        head->next = item;
        tail = size==1 ? item->next : tail;
    }

    void pop_front()
    {
        if (head->next) {
            auto temp = head->next;
            head->next = head->next->next;
            delete temp;
        }
        tail = size==0 ? nullptr : tail;
    }

    bool empty()
    {
        return size == 0;
    }

    ElemT front()
    {
        return head->next->content;
    }

    iterator begin()
    {
        return iterator(head->next);
    }

    iterator end()
    {
        return iterator(tail);
    }

};
#endif //MYSTANDARDALGOLIB_FORWARD_LIST_HPP
