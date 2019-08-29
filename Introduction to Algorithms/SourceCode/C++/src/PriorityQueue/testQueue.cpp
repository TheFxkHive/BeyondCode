#include <iostream>
using namespace std;
#include <vector>
#include "Heap.hpp"
#include "PriorityQueue.hpp"


void testadjustup()
{
    vector<int> a;
    a.push_back(7);
    adjustup(a);
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    cout << endl;
    a.push_back(6);
    adjustup(a);
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    cout << endl;
    a.push_back(5);
    adjustup(a);
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    cout << endl;
    a.push_back(4);
    adjustup(a);
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    cout << endl;
    a.push_back(3);
    adjustup(a);
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    cout << endl;
    a.push_back(2);
    adjustup(a);
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    cout << endl;
    a.push_back(1);
    adjustup(a);
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    cout << endl;
}
void testHeap()
{
    vector<int> a;
    a.push_back(7);
    a.push_back(6);
    a.push_back(5);
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);


    GetHeap(a);

    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
}
void testPriority()
{
    PriQueue<int> que;
    que.Push(5);
    que.Push(4);
    que.Push(3);
    que.Push(2);
    que.Push(1);

    while(que.Size() > 0)
    {
        cout << que.Pop() <<" ";
    }
    cout << std::endl;
}
int main()
{
    //testHeap();
    //testPriority();
    testadjustup();
    return 0;
}
