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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> v;
        map<int, vector<int>> mp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int l = 1;
        while (!q.empty())
        {
            int sz = q.size();
            unordered_map<int, vector<int>> m;
            for (int i = 0; i < sz; i++)
            {
                pair<TreeNode *, int> t;
                t = q.front();
                q.pop();
                // cout<<t.first->val<<" ";
                if (!t.first)
                    continue;
                m[t.second].push_back(t.first->val);

                if (t.first->left)
                {
                    q.push({t.first->left, t.second - 1});
                }
                if (t.first->right)
                {
                    q.push({t.first->right, t.second + 1});
                }
            }
            for (auto i : m)
            {
                sort(i.second.begin(), i.second.end());
                for (auto j : i.second)
                    mp[i.first].push_back(j);
            }
            l++;
            // cout<<endl;
        }
        for (auto i : mp)
        {
            // vector<int> a;
            // for(auto j:i.second) a.push_back(j.first);
            v.push_back(i.second);
        }

        return v;
    }
};