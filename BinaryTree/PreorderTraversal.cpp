/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;

};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {

        stack<TreeNode *> st;
        vector<int> ans;
        if (!root)
            return ans;

        st.push(root);

        while (!st.empty())
        {

            TreeNode *t = st.top();
            ans.push_back(t->val);
            st.pop();

            if (t->right)
                st.push(t->right);
            if (t->left)
                st.push(t->left);
        }

        return ans;
    }
};