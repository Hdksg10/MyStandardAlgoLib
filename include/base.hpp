//
// Created by Rhywu on 2022/4/10.
//

#ifndef MYSTANDARDALGOLIB_BASE_HPP
#define MYSTANDARDALGOLIB_BASE_HPP
#include <iostream>
using size_t = unsigned long long int;
template<typename T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
unsigned int testSize(T* array)
{

    unsigned long int s = uintptr_t(array);
    unsigned long int r = uintptr_t(array+1);
    std::cout<<r-s<<std::endl;
    return r-s;
}

template<typename IterT>
size_t distance(IterT begin, IterT end)
{
    size_t dist = 0;
    while(begin != end)
    {
        begin++;
        dist++;
    }
    return dist;
}
template<typename IterT>
size_t random_access_distance(IterT begin, IterT end)
{
    size_t dist = end - begin;
    return dist;
}

template<typename ElemT>
ElemT*& begin(ElemT* array)
{
    static auto iter = array;
    return &iter;
}

template<typename InputIt1, typename InputIt2, typename OutputIt>
OutputIt merge(InputIt1 first_begin, InputIt1 first_end, InputIt2 second_begin, InputIt2 second_end, OutputIt output_start)
{
    while(first_begin != first_end && second_begin != second_end)
    {
        if(*first_begin < *second_begin)
        {
            *output_start = *first_begin;
            output_start++;
            first_begin++;
        }
        else
        {
            *output_start = *second_begin;
            output_start++;
            second_begin++;
        }
    }
    if(first_begin == first_end)
    {
        while(second_begin != second_end)
        {
            *output_start = *second_begin;
            output_start++;
            second_begin++;
        }
    }
    else
    {
        while(first_begin != first_end)
        {
            *output_start = *first_begin;
            output_start++;
            first_begin++;
        }
    }
    return output_start;
}
#endif //MYSTANDARDALGOLIB_BASE_HPP
