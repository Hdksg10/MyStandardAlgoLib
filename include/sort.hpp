//
// Created by Rhywu on 2022/4/7.
//

#ifndef MYSTANDARDALGOLIB_SORT_HPP
#define MYSTANDARDALGOLIB_SORT_HPP
#include "base.hpp"

namespace ctd {
    template<typename IterT>
    void insertion_sort(IterT left_iter, IterT right_iter) {
        //size_t diff = std::distance(left_iter, right_iter);
        IterT curr_iter = left_iter + 1;
        while (curr_iter != right_iter) {
            IterT swap_iter = curr_iter;
            while (swap_iter != left_iter && *swap_iter < *(swap_iter - 1)) {
                std::swap(*(swap_iter - 1), *swap_iter);
                swap_iter--;
            }
            curr_iter++;
        }
    }

    template<typename IterT, typename FuncT>
    void insertion_sort(IterT left_iter, IterT right_iter, FuncT cmp) {
        IterT curr_iter = left_iter + 1;
        while (curr_iter != right_iter) {
            IterT swap_iter = curr_iter;
            while (swap_iter != left_iter && cmp(*(swap_iter), *(swap_iter - 1))) {
                std::swap(*(swap_iter - 1), *swap_iter);
                swap_iter--;
            }
            curr_iter++;
        }
    }

    template<typename IterT>
    void shell_sort(IterT left_iter, IterT right_iter)//only support random accessed iterator
    {
        size_t diff = std::distance(left_iter, right_iter);
        size_t h = 1;
        while (3 * h < diff) h = 3 * h + 1;
        while (h >= 1) {
            IterT curr_iter = left_iter + h;
            while (curr_iter < right_iter) {
                IterT swap_iter = curr_iter;
                while (swap_iter > left_iter && *swap_iter < *(swap_iter - h)) {
                    std::swap(*(swap_iter - h), *swap_iter);
                    swap_iter = swap_iter - h;
                }
                curr_iter = curr_iter + h;
            }
            h = h / 3;
        }

    }

    template<typename IterT, typename FuncT>
    void shell_sort(IterT left_iter, IterT right_iter, FuncT cmp)//only support random accessed iterator
    {
        size_t diff = std::distance(left_iter, right_iter);
        size_t h = 1;
        while (3 * h < diff) h = 3 * h + 1;
        while (h >= 1) {
            IterT curr_iter = left_iter + h;
            while (curr_iter < right_iter) {
                IterT swap_iter = curr_iter;
                while (swap_iter > left_iter && cmp(*swap_iter, *(swap_iter - h))) {
                    std::swap(*(swap_iter - h), *swap_iter);
                    swap_iter = swap_iter - h;
                }
                curr_iter = curr_iter + h;
            }
            h = h / 3;
        }

    }
//开发中
    template<typename IterT, typename ElemT>
    void do_mergesort(IterT left_iter, IterT right_iter, ElemT* temp_storage)
    {
        size_t size = random_access_distance(left_iter, right_iter);
        if(size <= 1)
            return;
        auto offset = size % 2 ? size / 2 + 1 : size / 2;
        do_mergesort(left_iter, left_iter + offset, temp_storage);
        do_mergesort(left_iter + offset, right_iter, temp_storage + offset);
        merge(left_iter, left_iter + offset, left_iter + offset, right_iter, temp_storage);
    }
    template<typename IterT>
    void mergesort(IterT left_iter, IterT right_iter)
    {
        using ElemT = typename IterT::value_type;
        size_t size = random_access_distance(left_iter, right_iter);
        ElemT temp[size];
        auto begin = temp;
        do_mergesort(left_iter, right_iter, begin);
        int i = 0;
        while(left_iter != right_iter)
        {
            *left_iter = temp[i];
            left_iter++;
            i++;
        }
    }

}
#endif //MYSTANDARDALGOLIB_SORT_HPP
