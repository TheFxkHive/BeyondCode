#include "sort.h"
#include "log.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>
int* BuildHeap(int* arr, int len)
{
    assert(arr);
    assert(len > 1);
    int child = 0;
    int father = 0;
    int begin = (len - 2) / 2;
    while(begin >= 0)
    {
        father = begin;
        child = father * 2 + 1;
        while(child < len)
        {
            int min = child;
            if (child + 1 < len)
                min = arr[child] < arr[child+1] ? child : child+1;
            if(arr[father] > arr[min])
            {
                std::swap(arr[father], arr[min]);
            }
            //if(father == 0)
            //{
            //    break;
            //}
            father = child;
            child = father * 2 + 1;
        }
        begin--;
        Logger(arr,5);
    }
    return arr;
}
