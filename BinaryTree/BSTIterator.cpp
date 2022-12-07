
/*
https://leetcode.com/problems/binary-search-tree-iterator/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        ln(root);
    }

    void ln(TreeNode *root)
    {
        TreeNode *t = root;
        while (t)
        {
            st.push(t);
            t = t->left;
        }
    }
    /** @return the next smallest number */
    int next()
    {
        TreeNode *t = st.top();
        st.pop();
        if (t->right)
            ln(t->right);

        return t->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {

        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */