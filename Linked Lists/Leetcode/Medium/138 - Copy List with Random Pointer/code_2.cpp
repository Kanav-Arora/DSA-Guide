#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        Node *clonedHead = new Node(head->val);
        Node *temp1 = head, *temp2 = clonedHead;
        unordered_map<Node *, Node *> mp;
        mp[head] = clonedHead;
        while (temp1->next)
        {
            temp1 = temp1->next;
            Node *node = new Node(temp1->val);
            mp[temp1] = node;
            temp2->next = node;
            temp2 = node;
        }

        temp1 = head;
        while (temp1)
        {
            Node *randomOrg = temp1->random;
            Node *nodeCopy = mp[temp1];
            nodeCopy->random = mp[randomOrg];
            temp1 = temp1->next;
        }
        return clonedHead;
    }
};