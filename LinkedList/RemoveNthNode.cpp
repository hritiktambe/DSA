

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *t = head;
        while (n > 0 and t)
        {
            n--;
            t = t->next;
        }

        if (!t)
            return head->next;

        ListNode *ans = head;

        while (t->next)
        {
            t = t->next;
            ans = ans->next;
        }

        ans->next = ans->next->next;

        return head;
    }
};