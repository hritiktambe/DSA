
/*
https : //leetcode.com/problems/permutations/submissions/
Explanation:
https://leetcode.com/problems/permutations/discuss/993970/Python-4-Approaches-%3A-Visuals-%2B-Time-Complexity-Analysis

In order to reaverse the tree, will visit each node once, we know very well that would cost us O(N) in a binary tree 
and O(E+V) in an N-ary tree where V = vertices and E = edges (or number of children).
Now for the [1,2,3] example shown in the sketch, we can see there is a total of 16 nodes/verticies and that |E| 
varies from level to level with an upper limit of N and a lower limit of 1.

            So, we can say roughly O(E+V) = a little more than 16
            O(N!) on the other hand = 6
            whereas, O(NN!) = 36 = 18

        Another way of looking at is we know from set theory that there are N! permutations of a list of size N. 
        We also know that the permutations are going to be the leaves of the tree, which means we will have N! leaves. 
        In order to get to each one of those leaves, we had to go through N calls. That's O(N*N!). Again a little more 
        than the total number of nodes because some nodes are shared among more than one path.

    Space: O(N!)

        Because you still need to store the permutations and there are N! of them even if the depth of the stack is maxed 
        out at N+1 (depth of the recursion space-tree is also N+1). See figure below.



*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void helper(int in, vector<int> nums, vector<vector<int>> &v)
    {
        if (in == nums.size() - 1)
        {

            v.push_back(nums);
            return;
        }

        for (int i = in; i < nums.size(); i++)
        {
            swap(nums[i], nums[in]);
            helper(in + 1, nums, v);
            swap(nums[i], nums[in]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> v;

        helper(0, nums, v);

        return v;
    }
};