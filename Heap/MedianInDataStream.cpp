

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    /** initialize your data structure here. */

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int bal = 0;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (!max_heap.size())
        {
            max_heap.push(num);
            return;
        }
        if (num > max_heap.top())
            min_heap.push(num), bal--;
        else
            max_heap.push(num), bal++;

        while (max_heap.size() > min_heap.size() + 1)
            min_heap.push(max_heap.top()), max_heap.pop();
        while (min_heap.size() > max_heap.size())
            max_heap.push(min_heap.top()), min_heap.pop();
    }

    double findMedian()
    {
        if ((min_heap.size() + max_heap.size()) & 1)
            return (double)max_heap.top();
        return ((double)max_heap.top() + min_heap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */