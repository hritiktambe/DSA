/*
https: //leetcode.com/problems/add-two-numbers/
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
    ListNode():val(0),next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode* t =new ListNode(),*h;
        h=t;
        while(l1 or l2 or carry>0)
        {
            int sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(carry>0)
            {
                sum+=carry;
                carry=0;
            }
            t->val = sum%10;
            
            carry = sum/10;
            if(l1 or l2 or carry)
            {
                t->next = new ListNode();
                t=t->next;
            }
            
            
        }
        
        
        return h;
        
        
    }
};