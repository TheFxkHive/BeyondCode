#include "sort.h"
#include "log.h"
#include <assert.h>
#include <stdlib.h>
#include <iostream>
static void Counting(int *arr, int len, int max)
{
    int* count_arr = (int*)malloc((max+1)*sizeof(int));
    assert(count_arr);
    for(int i = 0; i < max+1; ++i)
    {
        count_arr[i] = 0;
    }
    for(int i = 0; i < len; ++i)
    {
        count_arr[arr[i]]++;
    }
    int j = 0;
    for(int i = 0; i < max+1; i++)
    {
        while(count_arr[i] > 0)
        {
            arr[j] = i;
            j++;
            count_arr[i]--;
        }
    }
    free(count_arr);
}
int * CountingSort(int *arr, int len)
{
    int max = 0;
    for(int i = 0; i < len; ++i)
    {
        assert(arr[i] >= 0);
        if(arr[i] > max)
            max=arr[i];
    }
    Counting(arr, len , max);
    return arr;
}
