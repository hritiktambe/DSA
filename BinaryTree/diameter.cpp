

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};
class Solution
{

private:
    int diameter(TreeNode *root, int &path)
    {
        if (!root)
            return 0;
        int l = 0, r = 0;

        if (root->left)
            l = diameter(root->left, path);
        if (root->right)
            r = diameter(root->right, path);

        path = max(path, l + r + 1);

        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int path = 0;

        int tmp = diameter(root, path);

        return path - 1;
    }
};