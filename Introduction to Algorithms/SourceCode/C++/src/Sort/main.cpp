#include "sort.h"
#include "log.h"
int main()
{
        int a[] = {5,4,3,2,1};
        Logger(InsertSort(a,sizeof(a)/sizeof(int)),5);
        return 0;
}