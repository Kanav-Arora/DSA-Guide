#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return head;
        Node *temp = head;
        stack<Node *> stk;
        while (temp)
        {
            if (temp->child)
            {
                if (temp->next)
                    stk.push(temp->next);
                temp->child->prev = temp;
                temp->next = temp->child;
                temp->child = NULL;
            }
            if (!temp->next && !stk.empty())
            {
                Node *top = stk.top();
                stk.pop();
                temp->next = top;
                top->prev = temp;
            }
            temp = temp->next;
        }

        return head;
    }
};

int main()
{

    return 0;
}