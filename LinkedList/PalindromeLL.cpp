/*

find middle reverse second half of ll stop at last of second last node
now put pointer at start of list and move slow pointer by one

check half's of list

https://leetcode.com/problems/palindrome-linked-list/

*/

struct ListNode
{

    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *reverselist(ListNode *l)
    {
        if (!l)
            return NULL;

        ListNode *cur = l, *nex = l->next, *t = NULL;
        cur->next = NULL;
        while (nex)
        {
            t = nex->next;
            nex->next = cur;
            cur = nex;
            nex = t;
        }

        return cur;
    }

    bool isPalindrome(ListNode *head)
    {

        if (!head or !head->next)
            return true;

        ListNode *slow, *fast;

        slow = head;
        fast = head;

        while (fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverselist(slow->next);
        slow = slow->next;

        ListNode *d = head;

        while (slow)
        {
            if (slow->val != d->val)
                return false;
            slow = slow->next;
            d = d->next;
        }

        return true;
    }
};