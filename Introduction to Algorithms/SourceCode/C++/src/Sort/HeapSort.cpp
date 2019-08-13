#include "sort.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>
int* BuildHeap(int* arr, int len)
{
    assert(arr);
    assert(len > 1);
    int child = len - 1;
    int father = len - 1;
    int begin = len - 1;
    while(begin >= 0)
    {
        child = (begin+1) / 2;
        while(child > 0)
        {
            int min = arr[child] < arr[child-1] ? child : child-1;
            if(arr[father] > arr[min])
            {
                std::swap(arr[father], arr[min]);
            }
            child = (child / 2) - 1;
        }
        begin--;
        
    }
    return arr;
}
