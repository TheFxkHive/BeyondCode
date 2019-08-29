#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <iostream>
#include <vector>

template <class T>
struct CompMin
{
    bool operator() (const T& a, const T& b)
    {
        return a < b;
    }
};


template <class T, class Com = CompMin<T> >
inline void adjustdown(std::vector<T>& list, int index)
{
    int size = list.size();
    int father = index;
    int child = father * 2 + 1;
    Com compmin;
    while(child < size)
    {
        if(child + 1 < size)
            child = compmin(list[child], list[child + 1]) ? child : child + 1;
        if(!compmin(list[father], list[child]))
        {
            std::swap(list[father], list[child]);
            father = child;
            child = father * 2 + 1;
        }
        else
            break;
    }
}



template <class T, class Com = CompMin<T> >
inline void adjustup(std::vector<T>& list)
{
    int child = list.size() - 1;
    int father = 0;
    Com compmin;
    do {
        father = (child - 1) / 2;
//          no possible        
//        if(child % 2)
//            child = compmin(list[child], list[child-1]) ? child : child-1;
//        else if (child % 2 == 0 && child + 1 != list.size())
//            child = compmin(list[child], list[child+1]) ? child : child+1;
        if(!compmin(list[father], list[child]))
        {
            std::swap(list[father], list[child]);
            child = father;
        }

    } while(father > 0);
}


template <class T>
void GetHeap(std::vector<T>& list)
{
    int size = list.size();
    int begin = (size - 2) / 2;
    while(begin >= 0)
    {
        adjustdown(list, begin);
        begin--;
    }
}
#endif //_HEAP_HPP_
