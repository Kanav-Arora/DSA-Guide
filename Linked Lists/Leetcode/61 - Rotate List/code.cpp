#include <iostream>

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *it = head;
        int len = 1;
        while (it->next)
        {
            it = it->next;
            len++;
        }
        int rot = k % len;
        if (rot == 0)
            return head;
        it->next = head;
        ListNode *it2 = head;
        int steps = len - rot - 1;
        while (steps--)
        {
            it2 = it2->next;
        }
        ListNode *ans = it2->next;
        it2->next = NULL;
        return ans;
    }
};