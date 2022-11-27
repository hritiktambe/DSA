/*

https://leetcode.com/problems/search-a-2d-matrix/

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