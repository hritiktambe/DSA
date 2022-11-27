/*
https: //leetcode.com/problems/intersection-of-two-linked-lists/

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *t1 = headA, *t2 = headB;

        while (t1 != t2)
        {

            t1 = !t1 ? headB : t1->next;
            t2 = !t2 ? headA : t2->next;
        }

        return t1;
    }
};