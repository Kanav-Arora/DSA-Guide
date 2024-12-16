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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *less = dummy1, *more = dummy2;
        ListNode *it = head;
        while (it != NULL)
        {
            if (it->val < x)
            {
                less->next = it;
                less = less->next;
            }
            else
            {
                more->next = it;
                more = more->next;
            }
            it = it->next;
        }
        more->next = NULL;
        less->next = dummy2->next;
        return dummy1->next;
    }
};