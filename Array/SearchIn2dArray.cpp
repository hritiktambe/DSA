/*

https://leetcode.com/problems/search-a-2d-matrix/
https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

*/

//sol 1 using binary search

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int n = matrix.size(), m = matrix[0].size();

        int lo = 0;
        int high = n * m - 1;
        while (lo <= high)
        {
            int mid = lo + (high - lo) / 2;

            if (matrix[mid / m][mid % m] == target)
                return true;
            if (matrix[mid / m][mid % m] < target)
                lo = mid + 1;
            else if (matrix[mid / m][mid % m] > target)
                high = mid - 1;
        }

        return false;
    }
};

//sol 2