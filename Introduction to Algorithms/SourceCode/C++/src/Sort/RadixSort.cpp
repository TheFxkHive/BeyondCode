#include "sort.h"
#include "log.h"
#include <assert.h>

#include <iostream>
int * RadixSort(int *arr, int len)
{
    int max = arr[0];
    for(int i = 0; i < len; ++i)
    {
        assert(arr[i] > 0);
        if(arr[i] > max)
            max = arr[i];
    }

    int radix_times = 0;
    while(max != 0)
    {
        max /= 10;
        radix_times++;
    }

    int redix = 1;
    for(int i = 0; i < radix_times; ++i)
    {
        //insert sort
        for(int index = 0; index < len; ++index)
        {
            int insert_val = (arr[index] / redix) % 10;
            for(int pos = index - 1; pos >= 0; --pos)
            {
                if((arr[pos] / redix) % 10 > insert_val)
                {
                    arr[pos+1] = arr[pos];
                }
                if(pos == 0 || (arr[pos]/redix) % 10 <= insert_val)
                {
                    arr[pos] = insert_val;
                    break;
                }
            }
        }
        redix *= 10;
    }
    return arr;
}
