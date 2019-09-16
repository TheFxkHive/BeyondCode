#include "sort.h"
#include "log.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>
static int* Stooge(int* arr, int i, int j)
{
    int round = (j-i+1)/3;
    if(arr[i] > arr[j])
        std::swap(arr[i], arr[j]);
    if(i+1 >= j)
        return arr;
    Stooge(arr, i, j-round);
    Stooge(arr, i+round, j);
    Stooge(arr, i, j-round);
    return arr;
}
int* StoogeSort(int* arr, int len)
{
    Stooge(arr, 0, len-1);
    return arr;
}
