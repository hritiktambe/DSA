

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);

        TreeNode *r = lowestCommonAncestor(root->right, p, q);

        if ((l and r) or root == p or root == q)
            return root;

        return l ? l : r;
    }
};