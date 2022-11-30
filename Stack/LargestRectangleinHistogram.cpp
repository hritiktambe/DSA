
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        if (!heights.size())
            return 0;

        stack<int> h, pos;
        h.push(heights[0]);
        pos.push(0);
        int n = heights.size(), largest = 0;
        for (int i = 1; i < n; i++)
        {
            if (pos.empty())
            {
                pos.push(i), h.push(heights[i]);
                continue;
            }

            if (!h.empty() and heights[i] < h.top())
            {
                int t, p;

                while (!h.empty() and heights[i] < h.top())
                {
                    t = h.top(), p = pos.top();

                    largest = max(largest, t * (i - p));
                    h.pop();
                    pos.pop();
                }

                pos.push(p), h.push(heights[i]);
            }

            if (heights[i] != h.top())
                pos.push(i), h.push(heights[i]);
        }

        while (!h.empty())
        {
            int t = h.top(), p = pos.top();

            largest = max(largest, t * (n - p));
            h.pop(), pos.pop();
        }

        return largest;
    }
};