#include <iostream>
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
        if (head == NULL)
            return NULL;
        Node *temp = head;
        while (temp)
        {
            Node *n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = n->next;
        }

        temp = head;

        while (temp)
        {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node *newHead = head->next;
        temp = head;

        while (temp)
        {
            Node *n = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            if (temp)
            {
                n->next = temp->next;
            }
        }

        return newHead;
    }
};