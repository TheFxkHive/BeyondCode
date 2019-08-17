#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <iostream>
#include <vector>

template <class T>
void GetHeap(std::vector<T>& list)
{
    int size = list.size();
    int begin = (size - 2) / 2;
    while(begin >= 0)
    {
        int father = begin;
        int child = father * 2 + 1;
        while(child < size)
        {
            if(child + 1 < size)
                child = list[child] < list[child+1] ? child : child+1;
            if(list[father] < list[child])
            {
                std::swap(list[father], list[child]);
                fahter = child;
                child = father * 2 + 1;
            }
            else
                break;
        }
    }
}

#endif //_HEAP_HPP_
