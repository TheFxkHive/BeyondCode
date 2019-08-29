#ifndef __PRIORITY_QUEUE_HPP_
#define __PRIORITY_QUEUE_HPP_
#include <condition_variable>

#include "Heap.hpp"
template <class T>
class PriQueue
{
public:
    PriQueue()
    {
    }
    ~PriQueue(){}
    void Push(const T& a)
    {
        std::lock_guard<std::mutex>lk(mut);
        list.push_back(a);
        adjustup(list);
        var_cond.notify_one();
    }
    const T Pop()
    {
        std::unique_lock<std::mutex>lk(mut);
        var_cond.wait(lk, [this] {return !this->list.empty();});
        std::swap(list[0], list[list.size() - 1]);
        T value = list.back();
        list.pop_back();
        adjustdown(list, 0);
        return value;
    }
    const int Size()
    {
        return list.size();
    }
protected:
    mutable std:: mutex mut;
    std::condition_variable var_cond;
    std::vector<T> list;
};




#endif //__PRIORITY_QUEUE_HPP_
