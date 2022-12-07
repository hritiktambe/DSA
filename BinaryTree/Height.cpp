

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
    int maxDepth(TreeNode *root)
    {

        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};