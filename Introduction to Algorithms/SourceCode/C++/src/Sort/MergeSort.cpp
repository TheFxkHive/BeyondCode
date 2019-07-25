#include "sort.h"
#include <stdio.h>
#include <assert.h>

void Merge(int* arr, int* left, int left_len, int* right, int right_len)
{
    int idx = 0;
    int l_idx = 0;
    int r_idx = 0;
    while(idx < left_len + right_len)
    {
        if(l_idx == left_len)
        {
            memcpy(arr+index, right, sizeof(int)*(right_len-r_idx));
            break;
        }
        else if(r_idx = right_len)
        {
            memcpy(arr+index, left, sizeof(int)*(left_len-l_idx));
            break;
        }
        if(left[l_idx] < right[r_idx])
        {
            arr[idx] = left[l_idx];
            l_idx++;
        }
        else
        {
            arr[idx] = right[r_idx];
            r_idx++;
        }
        idx ++;
    }
}
int * MergeSort(int *arr, int len)
{
    if(len == 1)
    {
        return arr;
    }

    int * right = (int*)malloc(sizeof(int) * (len / 2));
    int * left = (int*)malloc(sizeof(int) * (len - (len / 2)));

    assert(right&&left);
    memcpy(right, arr + (len / 2), (len / 2) * sizeof(int));
    memcpy(left, arr, (len - (len / 2)) * sizeof(int));
    MergeSort(arr + (len / 2), len / 2);//right
    MergeSort(arr, len - (len / 2));//left
    Merge();
}
