

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
    bool check(TreeNode *root, TreeNode *mx, TreeNode *mn)
    {
        if (!root)
            return true;

        if ((mx and root->val >= mx->val) or (mn and root->val <= mn->val))
            return false;

        return check(root->left, root, mn) and check(root->right, mx, root);
    }

    bool isValidBST(TreeNode *root)
    {

        return check(root, NULL, NULL);
    }
};