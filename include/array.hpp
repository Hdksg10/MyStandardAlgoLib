//
// Created by Rhywu on 2022/4/10.
//

#ifndef MYSTANDARDALGOLIB_ARRAY_HPP
#define MYSTANDARDALGOLIB_ARRAY_HPP
#include "base.hpp"
namespace ctd {

    template<typename ElemT>
    class array_iterator {
    private:
        int pos;
        ElemT* array;
    public:
        using typevalue = ElemT;
        explicit array_iterator(int position, ElemT* target):pos(position), array(target){}
        typevalue& operator*()
        {
            return array[pos];
        }

        array_iterator operator++()
        {
            pos++;
            return
        }
        array_iterator operator++(int)
        {
            pos++;
        }

    };
    template<typename ElemT>
    class array_citerator {
    private:
        int pos;
    public:
        using typevalue = ElemT;

    };

    template<typename ElemT, int length>
    class array {
    public:
        using typevalue = ElemT;
        using iterator =  array_iterator<typevalue>;
        array()
        {
            content = new typevalue[length];
        }
        ~array()
        {
            delete[] content;
        }
        typevalue& operator[](int index)
        {
            if(index >= 0 && index < length)
                return content[index];
        }
        typevalue& front()
        {
            return content[0];
        }
        typevalue& back()
        {
            return content[length-1];
        }
        size_t size()
        {
            return length;
        }

        void fill(typevalue target){
            for (int i = 0; i < length; i++)
            {
                content[i] = target;
            }
        }
    private:
        typevalue* content;

    };
}
#endif //MYSTANDARDALGOLIB_ARRAY_HPP
