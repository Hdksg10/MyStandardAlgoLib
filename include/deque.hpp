//
// Created by RhyWu on 2022/4/7.
//
//需要重写vector
#ifndef MYSTANDARDALGOLIB_DEQUE_HPP
#define MYSTANDARDALGOLIB_DEQUE_HPP
#include "base.hpp"


namespace ctd{
    template<typename ElemT>
    class deque{
        using typevalue = ElemT;
    private:
        typevalue** _map;
        size_t _buffSize;
        size_t _mapSize;
        size_t _ctl;
        size_t _front;
        size_t _frontBuff;
        size_t _back;
        size_t _backBuff;
        void _mapResize()
        {
            typevalue** newMap;
            newMap = new typevalue*[2*_mapSize];
            for (int i = 0; i < _mapSize; i++)
            {
                newMap[_ctl + i] = _map[i];
            }
            _ctl = _mapSize;
            _mapSize = 2 * _mapSize;
            _frontBuff = _ctl - 1;
            _backBuff = _ctl;

        }
    public:
        deque()
        {
            _buffSize = 100;
            _mapSize = 50;
            _map = new typevalue*[_mapSize];
            _ctl = _mapSize / 2;
            _front = 0;
            _frontBuff = _ctl - 1;
            _back = 0;
            _backBuff = _ctl;
        }
        ~deque()
        {
            for (auto& i : _map)
                delete[] i;
        }
        void push_front(const typevalue& val)
        {
            if(_front == _buffSize)
            {
                _front = 0;
                _frontBuff;
            }
            else
            {
                _map[_frontBuff][_front] = val;
                _front++;
            }




        }



    };
}

#endif //MYSTANDARDALGOLIB_DEQUE_HPP
