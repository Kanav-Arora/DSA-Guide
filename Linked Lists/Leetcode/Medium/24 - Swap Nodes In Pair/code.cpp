#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = swapNodes(head->next->next);
        head->next->next = head;
        ListNode *temp = head->next;
        head->next = newHead;
        return temp;
    }

    ListNode *swapPairs(ListNode *head)
    {
        return swapNodes(head);
    }
};