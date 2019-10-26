#include <iostream>

#include "log.h"
#include "select.h"

using namespace std;

int main()
{
    int a[] = {5,4,3,2,1};
    cout << RandomSelect(a,0,4,1) << endl;
    int b[] = {5,4,3,2,1};
    cout << RandomSelect(b,0,4,2) << endl;
    int c[] = {5,4,3,2,1};
    cout << RandomSelect(c,0,4,3) << endl;
    int d[] = {5,4,3,2,1};
    cout << RandomSelect(d,0,4,4) << endl;
    return 0;
}
