

/*
https://leetcode.com/problems/min-stack/
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{

    stack<int> st;
    stack<int> mini;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);

        if (mini.empty())
            mini.push(val);
        else
        {
            if (val > mini.top())
                mini.push(mini.top());
            else
                mini.push(val);
        }
    }

    void pop()
    {
        if (!st.empty())
            st.pop();
        if (!mini.empty())
            mini.pop();
    }

    int top()
    {

        return st.top();
    }

    int getMin()
    {

        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */