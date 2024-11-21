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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *temp1 = list1, *temp2 = list2, *new_head = NULL;

        if (temp1 == NULL)
        {
            return temp2;
        }
        else if (temp2 == NULL)
        {
            return temp1;
        }

        if (list1->val < list2->val)
        {
            new_head = list1;
            temp1 = temp1->next;
        }
        else
        {
            new_head = list2;
            temp2 = temp2->next;
        }

        ListNode *temp = new_head;

        while (temp1 && temp2)
        {
            if (temp1->val < temp2->val)
            {
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }

        while (temp1)
        {
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }

        while (temp2)
        {
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }

        return new_head;
    }
};