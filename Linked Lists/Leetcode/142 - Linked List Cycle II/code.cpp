#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *findNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        bool cycleExists = false;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cycleExists = true;
                break;
            }
        }
        if (!cycleExists)
        {
            return NULL;
        }
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    ListNode *detectCycle(ListNode *head)
    {
        ListNode *cycleNode = findNode(head);
        return cycleNode;
    }
};