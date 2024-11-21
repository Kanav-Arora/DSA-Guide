#include <iostream>
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
        if (head == NULL)
            return NULL;
        Node *temp = head, *prev = NULL;
        stack<Node *> st;
        st.push(head);
        while (st.size() > 0)
        {
            Node *node = st.top();
            st.pop();

            // Doubly Linking last terminal to popped node
            if (prev)
            {
                node->prev = prev;
                prev->next = node;
            }

            // Setting temp to node for starting iteration from node
            temp = node;

            // Loop requires both check to edge cases such as if all nodes are child with no next node.
            while (temp && (temp->next || temp->child))
            {
                if (temp->child)
                {
                    // Edge Condition: If current node has child node but no next node
                    if (temp->next)
                        st.push(temp->next);
                    temp->next = temp->child;
                    temp->child->prev = temp;
                    temp->child = NULL;
                }
                temp = temp->next;
            }
            // On reaching terminal node, setting prev to store last visted node.
            prev = temp;
        }

        // At end setting last node next to NULL
        temp->next = NULL;
        return head;
    }
};