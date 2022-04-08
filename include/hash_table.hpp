//
// Created by Rhywu on 2022/4/7.
//

#ifndef MYSTANDARDALGOLIB_HASH_TABLE_HPP
#define MYSTANDARDALGOLIB_HASH_TABLE_HPP
#include <vector>
#include <list>
#include <cmath>

template <typename ElementT>
class hashTable
{
private:
    double _loadFactor;//装载因子，决定何时进行rehash

    int _size;//哈希表中元素个数
    int _tableSize;//哈希表表长
    int _primeIndex;//表长对应的质数表索引
    bool _reHashState;//是否开启rehash
    std::vector<std::list<ElementT>> _table;//采用std::vector实现的哈希表，元素是stl中双向链表
    inline static unsigned long _primeList[29] = {
            29,53,97,193,389,769,1543,3079,6151,12289,24593,49157,98317,
            196613,393241,786433,1572869,3145739,6291469,12582917,25165843,50331653,100663319,
            201326611,402653189,805306457,1610612741,3221225473ul,4294967291ul
    };//质数表来源：SGI STL中HashMap的实现  用于决定哈希表表长与哈希算法
    //哈希算法，余数法
    [[nodiscard]] int _hash(int key)const//key为关键字
    {
        return abs((key % _tableSize));
    }
    [[nodiscard]] int _hash(long key)const
    {
        return abs((key % _tableSize));
    }
    [[nodiscard]] int _hash(short key)const
    {
        return abs((key % _tableSize));
    }
    [[nodiscard]] int _hash(unsigned long key)const
    {
        return (key % _tableSize);
    }
    [[nodiscard]] int _hash(unsigned short key)const
    {
        return (key % _tableSize);
    }
    [[nodiscard]] int _hash(unsigned int key)const
    {
        return (key % _tableSize);
    }

    //rehash操作，在装载因子达到阈值(默认0.75)时执行
    void _rehash()
    {
        _primeIndex++;
        _tableSize = _primeList[_primeIndex];//获取rehash后的表长
        std::vector<std::list<ElementT>> _new_table;
        _new_table.resize(_tableSize);//创建临时表
        for(auto list : _table)
        {
            for(auto item : list)
            {
                _new_table[__hash(item)].push_front(item);
            }
        }//重新计算hash值并转移到临时表中
        _table.resize(_tableSize);//旧表扩容
        _table = std::move(_new_table);//通过浅拷贝将临时表拷贝到旧表
    }
public:
    //构造函数，进行初始化工作
    hashTable()
    {
        _loadFactor = 0.75;
        _size = 0;
        _primeIndex = 0;
        _tableSize = _primeList[_primeIndex];
        _table.resize(_tableSize);
        _reHashState = true;//默认开启rehash
    }
    //析构函数，暂时不需要操作

    //插入操作
    void add(const ElementT val)//val为添加元素
    {
        _table[__hash(val)].push_front(val);
        _size++;//计算hash值，添加元素
        if(_size > _tableSize * _loadFactor && _reHashState)
        {
            _rehash();
        }//在插入后判断是否需要rehash，此处耗时较长导致线程阻塞
    }
    //查询操作
    bool find(const ElementT val)const//val为查询元素
    {
        int hash_val = __hash(val);
        auto bucket = &_table[hash_val];//计算hash值，获取所在的链表
        if(bucket->empty())
            return false;//链表为空则肯定不存在
        else
        {
            auto currIter = bucket->begin();
            auto endIter = bucket->end();
            while (currIter != endIter)
            {
                if(*currIter == val)
                {
                    return true;
                }
                currIter++;
            }
            return false;
        }//遍历链表查询
    }
    //设置是否开启rehash
    void setReHash(bool isReHash)//isReHash 控制 rehash开启状态
    {
        _reHashState = isReHash;
    }
    //重置哈希表，释放空间，成员重新初始化
    void clear()
    {
        _table.clear();
        _loadFactor = 0.75;
        _size = 0;
        _primeIndex = 0;
        _tableSize = _primeList[_primeIndex];
        _table.resize(_tableSize);
    }
    //返回哈希表元素个数
    int size()
    {
        return _size;
    }
    //返回表长
    int tableSize()
    {
        return _table.size();
    }


};
#endif //MYSTANDARDALGOLIB_HASH_TABLE_HPP
