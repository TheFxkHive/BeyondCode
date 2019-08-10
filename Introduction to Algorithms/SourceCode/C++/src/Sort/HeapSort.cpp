#include "sort.h"
#include <stdio.h>
#include <assert.h>

int* BuildHeap(int* arr, int len)
{
    assert(arr);
    assert(len > 1);
    int left = len - 2;
    int right = len - 1;
    int father = right / 2 - 1;
    do {
        int max = arr[left] > arr[right] ? left : right;
        if(arr[father] < arr[max])
        {
            std::swap(arr[father], arr[max]);
        }
        
    } while(father != 0);
    return arr;
}
