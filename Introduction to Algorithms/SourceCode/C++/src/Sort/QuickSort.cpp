#include "sort.h"
#include "log.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>
int* QuickSort(int* arr, int len)
{
    int lower = 0;
    int heigher = 0;

    if(len < 2)
        return arr;


    while(heigher < len - 1)
    {
        if(arr[heigher] < arr[len - 1])
        {
            std::swap(arr[lower], arr[heigher]);
            ++lower;
        }
        heigher++;
    }

    std::swap(arr[lower], arr[heigher]);

    Logger(arr, len);
    QuickSort(arr, lower);
    QuickSort(arr+lower, len-lower);
    return arr;
}
