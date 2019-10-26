#include "log.h"
#include "select.h"
#include <iostream>
#include <cassert>

int RandomPartion(int * arr, int begin, int end)
{
     assert(begin >= 0 && end - begin > 0);
     int lower = begin;
     int heigher = begin;
     while(heigher <= end)
     {
         if(arr[heigher] < arr[end])
         {
             std::swap(arr[heigher], arr[lower]);
             lower++;
         }
         heigher++;
     }
     std::swap(arr[end], arr[lower]);
     Logger(arr, 5);
     return lower;

}
int RandomSelect(int* arr, int begin, int end, int pos)
{
     assert(begin >= 0 && end - begin >= 0);
     if(end - begin < 1)
         return arr[begin];
     int idx = RandomPartion(arr, begin, end);
     if(idx == pos)
         return arr[idx];
     if(idx < pos)
         return RandomSelect(arr, idx+1, end, pos);
     else
         return RandomSelect(arr, begin, idx-1, pos);
}
