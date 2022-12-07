

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
    int helper(TreeNode *root)
    {

        if (!root)
            return 0;

        int l = 0, r = 0;

        if (root->left)
            l = helper(root->left);

        if (l == -1)
            return -1;

        if (root->right)
            r = helper(root->right);

        if (r == -1)
            return -1;

        if (abs(l - r) > 1)
            return -1;

        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode *root)
    {

        return helper(root) == -1 ? false : true;
    }
};