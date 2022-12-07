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
    TreeNode* left, *right;

};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> ans;

        if (!root)
            return ans;
        stack<TreeNode *> st;

        TreeNode *t = root;

        while (t)
        {

            st.push(t);
            t = t->left;
        }

        while (!st.empty())
        {

            t = st.top();
            ans.push_back(t->val);
            st.pop();

            t = t->right;

            while (t)
            {
                st.push(t);
                t = t->left;
            }
        }

        return ans;
    }
};