
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val <= list2->val)
            list1->next = mergeTwoLists(list1->next, list2);
        else
        {

            list2->next = mergeTwoLists(list1, list2->next);
            list1 = list2;
        }

        return list1;
    }
};