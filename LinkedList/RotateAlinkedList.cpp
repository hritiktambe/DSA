/*

Take modulus of times the list is to be rotated k=k%sisze()
if it is zero return the list as it is
else

move a front pointer forward by k steps and then assign another pointer at the start
when the front pointer reaches the last node , join the last and first node

and set next of back as null

https://leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head or !head->next)
            return head;
        int count = 0;
        ListNode *t = head;

        while (t)
            t = t->next, count++;

        k = k % count;

        if (k == 0)
            return head;

        ListNode *front = head, *back = head;

        while (k--)
            front = front->next;

        while (front->next)
        {
            front = front->next;
            back = back->next;
        }

        front->next = head;

        ListNode *ans = back->next;

        back->next = NULL;

        return ans;
    }
};