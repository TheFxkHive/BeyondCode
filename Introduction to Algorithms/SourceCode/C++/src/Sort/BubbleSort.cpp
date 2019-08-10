#include "sort.h"
#include "log.h"
#include <assert.h>

#include <iostream>
int * BubbleSort(int *arr, int len)
{
    for(int i = 0; i < len; ++i)
    {
        for(int j = i; j >= 0; --j)
        {
            if(arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
    return arr;
}
