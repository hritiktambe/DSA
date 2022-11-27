/*

https://leetcode.com/problems/delete-node-in-a-linked-list/

*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *t2 = node->next;

        while (t2->next)
        {
            node->val = t2->val;
            node = node->next;
            t2 = t2->next;
        }
        node->val = t2->val;
        node->next = NULL;
    }
};