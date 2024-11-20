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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy, *curr = head;
        while (curr)
        {
            if (curr->next != NULL && curr->val == curr->next->val)
            {
                while (curr->next != NULL && curr->val == curr->next->val)
                {
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};