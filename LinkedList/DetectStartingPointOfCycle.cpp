

/*
Let's Do some math work. To understand this solution, you just need to ask yourself this question.

    Assume the distance from head to the start of the loop is x1
        the distance from the start of the loop to the point fast and slow meet is x2
            the distance from the point fast and slow meet to the start of the loop is x3

                What is the distance fast moved
    ? What is the distance slow moved
    ? And their relationship ?

                             x1 + x2 + x3 + x2 
                             x1 + x2 
                             x1 + x2 + x3 + x2 = 2(x1 + x2)

                                 Q
                             : Now your question Why x1 + x2 + x3 + x2 = 2(x1 + x2) ?

Ans
: Its just the relationship between the distance travelled by fast pointer and the distance travelled by the 
slow pointer.As fast pointer,runs twice the speed of slow pointer.
Therefore, when they meet, distance travelled by fast pointer will be 2 * (distance travelled by slow pointer).
Therefore,
x1 = x3.

*/
#include <bits/stdc++.h>
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
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow = head, *fast = head;

        while (fast and fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *entry = head;
                while (slow != entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};