

#include <bits/stdc++.h>
using namespace std;

class Maxheap
{

    vector<int> a;

    int sz()
    {
        return a.size();
    }

    int parent(int x)
    {
        return (x-1)/2;
    }

    int left(int x)
    {
        return (x<<1)+1;
    }

    int right(int x)
    {
        return (x<<1)+2;
    }

    void heapify(int idx)
    {
        int l =left(idx) , r=right(idx);

        int largest = idx;

        if(l<sz() and a[l]>a[largest])
        largest = l;

        if(r<sz() and a[r]>a[largest])
        largest = r;

        if(largest!=idx)
        {
            swap(a[idx],a[largest]);
            heapify(largest);

        }

        return;
    }

    void heapify_up(int idx)
    {
        if(!idx) return ;

        int p = parent(idx);

        if(a[p]<a[idx])
        {
            swap(a[p],a[idx]);
            heapify_up(p);
        }

    }

    void push(int val)
    {
        a.push_back(val);
        heapify_up(sz() - 1);
    }

    int pop()
    {
        if(sz()<=0)
        return -1;

        int val = a[0];

        a[0]=a.back();
        a.pop_back();
        heapify(0);
        return val;
    }

    int top()
    {
        return a[0];
    }

};