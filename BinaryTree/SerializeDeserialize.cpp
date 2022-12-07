

/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {

        if (!root)
            return "x";

        string l = serialize(root->left);
        string r = serialize(root->right);

        return to_string(root->val) + "," + l + "," + r;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        queue<string> q;
        string a = "";

        for (auto i : data)
        {
            if (i == ',')
            {

                q.push(a);
                a = "";
                continue;
            }
            a += i;
        }

        return helper(q);
    }

    int toi(string s)
    {
        int a = 0, n = 1;
        for (auto i : s)
        {
            if (i == '-')
            {
                n = -1;
                continue;
            }

            a = a * 10 + (i - '0');
        }
        return a;
    }

    TreeNode *helper(queue<string> &q)
    {
        if (q.empty())
            return NULL;
        string t = q.front();

        q.pop();

        if (t == "x")
            return NULL;

        TreeNode *root = new TreeNode(toi(t));

        root->left = helper(q);
        root->right = helper(q);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));