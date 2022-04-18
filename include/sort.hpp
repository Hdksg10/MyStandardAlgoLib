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
/**
 * 归并排序
 * @tparam RandomAccessIter 仅支持随机访问迭代器
 * @param left_iter
 * @param right_iter
 */
    template<typename RandomAccessIter>
    void mergesort(RandomAccessIter left_iter, RandomAccessIter right_iter)
    {
        size_t dist = random_access_distance(left_iter, right_iter);
        if(dist <= 1)
            return;
        else
        {
            mergesort(left_iter, left_iter + dist/2);
            mergesort(left_iter + dist/2, right_iter);
            inplace_merge(left_iter, left_iter + dist/2, right_iter);
        }
    }

/**
 * Duplicate Keys Quick Sort
 * @tparam RandomAccessIter 仅支持随机访问迭代器
 * @param left_iter
 * @param right_iter
 */
    template<typename RandomAccessIter>
    void quicksort(RandomAccessIter left_iter, RandomAccessIter right_iter)
    {
        using ElemT = typename RandomAccessIter::value_type;
        size_t dist = random_access_distance(left_iter, right_iter);
        if(dist <= 1)
            return;
        ElemT pivot = *(left_iter+random_int(0, dist));
        auto min_iter = left_iter;
        auto max_iter = right_iter;
        auto equal_iter = min_iter;
        while(equal_iter != max_iter)
        {
            if(*equal_iter < pivot)
            {
                swap(*equal_iter, *min_iter);
                min_iter++;
                equal_iter++;
            }
            else if(*equal_iter > pivot)
            {
                swap(*equal_iter, *(max_iter-1));
                max_iter--;
            }
            else
            {
                equal_iter++;
            }
        }
        quicksort(left_iter, min_iter);
        quicksort(max_iter, right_iter);
    }

}

#endif //MYSTANDARDALGOLIB_SORT_HPP
