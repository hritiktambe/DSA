

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int val) : val(val), right(NULL), left(NULL) {}
};

class Solution
{
public:
    int in = 0, po = 0;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        in = inorder.size() - 1;
        po = postorder.size() - 1;

        return helper(inorder, postorder, INT_MIN);
    }

    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int stop)
    {
        if (po < 0)
            return NULL;

        if (inorder[in] == stop)
        {
            in--;
            return NULL;
        }

        TreeNode *node = new TreeNode(postorder[po--]);

        node->right = helper(inorder, postorder, node->val);

        node->left = helper(inorder, postorder, stop);

        return node;
    }
};