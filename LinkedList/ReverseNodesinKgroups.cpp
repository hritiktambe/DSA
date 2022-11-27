
/*
https://leetcode.com/problems/reverse-nodes-in-k-group/

*/

struct ListNode
{

    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *temp = new ListNode();

        ListNode *prev = temp, *cur = temp, *nex = temp, *t = head;

        int l = 0;
        while (t)
            t = t->next, l++;
        temp->next = head;
        while (l >= k)
        {
            cur = prev->next;
            nex = cur->next;
            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = prev->next;

                prev->next = nex;
                nex = cur->next;
            }
            prev = cur;
            l -= k;
        }

        return temp->next;
    }
};