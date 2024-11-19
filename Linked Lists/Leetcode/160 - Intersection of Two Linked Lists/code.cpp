#include <iostream>
#include <unordered_map>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, bool> mp;
        while (headA)
        {
            mp[headA] = true;
            headA = headA->next;
        }

        while (headB)
        {
            if (mp[headB])
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};