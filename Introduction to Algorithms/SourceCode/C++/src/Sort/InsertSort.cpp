#include "sort.h"
#include <stdio.h>
#include <assert.h>

int* InsertSort(int* arr, int len)
{
        assert(arr);
        assert(len > 1);

        for (int i = 1;i < len; ++i) {
                int insert_val = arr[i];
                for (int j  = i - 1; j >= 0; --j) {
                        if (arr[j] > insert_val ) {
                                arr[j + 1] = arr[j];
                        }

                        if(j == 0 || arr[j] <= insert_val) {
                                arr[j] = insert_val;
                                break;
                        }
                }
        }

        return arr;
}
