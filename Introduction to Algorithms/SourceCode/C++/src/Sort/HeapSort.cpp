#include "sort.h"
#include "log.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>

inline int* adjustdown(int* arr, int len, int index)
{
    assert(arr);
    assert(len > 0);
    assert(index < len && index >= 0);
    int father = index;
    int child = father * 2 + 1;
    while(child < len)
    {
        int min = child;
        if(child + 1 < len)
            min = arr[child] < arr[child+1] ? child : child+1;
        if(arr[father] > arr[min])
        {
            std::swap(arr[father], arr[min]);
        }
        father = min;
        child = father * 2 + 1;
    }
}

int* BuildHeap(int* arr, int len)
{
    assert(arr);
    assert(len > 1);
    int child = 0;
    int father = 0;
    int begin = (len - 2) / 2;
    while(begin >= 0)
    {
        adjustdown(arr, len, begin);
        begin--;
    }
    return arr;
}

int* HeapSort(int* arr, int len)
{
    
    BuildHeap(arr, len);
    while(len > 1)
    {
        std::swap(arr[0], arr[--len]);
        adjustdown(arr, len, 0);
        Logger(arr, 5);
    }

    return arr;
}
