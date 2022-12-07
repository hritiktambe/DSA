
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int val) : val(val) , right(NULL) , left(NULL) {}
};

class Solution
{
public:
    int in = 0, pr = 0;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(preorder, inorder, INT_MIN);
    }

    TreeNode *helper(vector<int> &pro, vector<int> &ino, int stop)
    {
        if (pr >= pro.size())
            return NULL;
        if (ino[in] == stop)
        {
            in++;
            return NULL;
        }

        TreeNode *node = new TreeNode(pro[pr++]);

        node->left = helper(pro, ino, node->val);
        node->right = helper(pro, ino, stop);

        return node;
    }
};