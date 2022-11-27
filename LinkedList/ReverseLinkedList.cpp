/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode{

    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr) {}

};


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (!head)
            return head;
        ListNode *t1, *t2, *t3;
        t1 = head, t2 = head->next, t3 = NULL;
        t1->next = NULL;
        while (t2)
        {
            t3 = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = t3;
        }

        return t1;
    }
};