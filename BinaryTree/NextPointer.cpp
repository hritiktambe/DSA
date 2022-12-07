

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right,*next;
};

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (!root)
            return NULL;

        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {

            int sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                Node *t = q.front();
                q.pop();

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);

                if (i == sz - 1)
                {
                    t->next = NULL;
                    continue;
                }

                t->next = q.front();
            }
        }

        return root;
    }
};