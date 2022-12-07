
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
    int ks(TreeNode *root, int &k)
    {
        if (!root)
            return 0;
        int l = ks(root->left, k);
        if (l)
            return l;
        k--;
        if (!k)
            return root->val;
        int r = ks(root->right, k);

        return r;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int ans = ks(root, k);

        return ans;
    }
};