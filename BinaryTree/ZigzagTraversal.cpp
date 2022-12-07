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
    TreeNode *left, *right;
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        bool odd = true;

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> v;
            for (int i = 0; i < sz; i++)
            {

                TreeNode *t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->right)
                    q.push(t->right);
                if (t->left)
                    q.push(t->left);
            }

            if (odd)
            {
                reverse(v.begin(), v.end());
                odd = false;
            }
            else
                odd = true;

            ans.push_back(v);
        }

        return ans;
    }
};