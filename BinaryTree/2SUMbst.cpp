/*

https: //leetcode.com/problems/two-sum-iv-input-is-a-bst/

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {

        return dfs(root, root, k);
    }

    bool dfs(TreeNode *root, TreeNode *cur, int k)
    {

        if (!cur)
            return false;

        return search(root, cur, k - cur->val) or dfs(root, cur->left, k) or dfs(root, cur->right, k);
    }

    bool search(TreeNode *root, TreeNode *cur, int k)
    {
        if (!root)
            return false;

        if (root->val == k and root != cur)
            return true;

        if (root->val < k and search(root->right, cur, k))
            return true;
        else if (root->val > k and search(root->left, cur, k))
            return true;

        return false;
    }
};