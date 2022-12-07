
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
    bool pos(TreeNode *t1, TreeNode *t2)
    {

        if (!t1 and !t2)
            return true;

        if (!t1 or !t2)
            return false;

        return t1->val == t2->val and pos(t1->right, t2->left) and pos(t1->left, t2->right);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return pos(root->left, root->right);
    }
};