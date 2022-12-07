

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
    int helper(TreeNode *root, int &path)
    {
        if (!root)
            return 0;

        int l = 0, r = 0;

        if (root->left)
            l = helper(root->left, path);
        if (root->right)
            r = helper(root->right, path);

        path = max(path, max(l + r + root->val, max(l + root->val, max(r + root->val, root->val))));

        return max(l + root->val, max(r + root->val, root->val));
    }

    int maxPathSum(TreeNode *root)
    {

        int path = INT_MIN;

        int t = helper(root, path);

        return path;
    }
};