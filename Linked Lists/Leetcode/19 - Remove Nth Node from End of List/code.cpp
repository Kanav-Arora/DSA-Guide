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
    pair<ListNode *, int> removeNode(ListNode *&head, int n)
    {
        if (head->next == NULL)
        {
            if (n == 1)
                return {NULL, -1};
            else
                return {head, 1};
        }

        pair<ListNode *, int> obj = removeNode(head->next, n);
        head->next = obj.first;
        if (obj.second == -1)
            return {head, -1};
        if (n == obj.second + 1)
            return {head->next, -1};
        return {head, obj.second + 1};
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        return removeNode(head, n).first;
    }
};