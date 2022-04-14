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
#endif //MYSTANDARDALGOLIB_BASE_HPP
