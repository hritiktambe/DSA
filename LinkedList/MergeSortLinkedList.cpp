#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */

Node *find_mid(Node *head)
{
    if (!head)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast and fast->next and fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge_list(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l2->data >= l1->data)
        l1->next = merge_list(l1->next, l2);
    else
    {
        l2->next = merge_list(l1, l2->next);
        l1 = l2;
    }
    return l1;
}

Node *mergeSort(Node *head)
{
    if (!head or !head->next)
    {
        return head;
    }
    Node *mid = find_mid(head);
    Node *midn = mid->next;

    mid->next = NULL;

    Node *f = mergeSort(head);
    Node *s = mergeSort(midn);

    Node *sl = merge_list(f, s);

    return sl;
}

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends