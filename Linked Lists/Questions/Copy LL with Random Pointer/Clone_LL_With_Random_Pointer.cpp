#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int val)
    {
        data = val;
        next = NULL;
        random = NULL;
    }
};

void InsertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    Node *temp = head;
    if (head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty linked list";
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *copyRandomListWithConstantSpace(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        Node *insert = new Node(temp->data);
        insert->next = temp->next;
        temp->next = insert;
        temp = insert->next;
    }

    temp = head;

    while (temp != NULL)
    {
        temp->next->random = temp->random;
        temp = temp->next->next;
    }

    temp = head;

    Node *new_head = temp->next;
    temp = new_head;

    while (temp->next != NULL)
    {
        temp->next = temp->next->next;
        temp = temp->next;
    }

    return new_head;
}

Node *copyRandomListWithMapping(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *clonehead = new Node(head->data);
    Node *temp = head->next;
    Node *temp2 = clonehead;

    while (temp != NULL)
    {
        Node *n = new Node(temp->data);
        temp2->next = n;
        temp2 = temp2->next;
        temp = temp->next;
    }

    unordered_map<Node *, Node *> mapping;
    temp = head;
    temp2 = clonehead;
    while (temp != NULL)
    {
        mapping[temp] = temp2;

        temp = temp->next;
        temp2 = temp2->next;
    }

    temp = head;
    temp2 = clonehead;

    while (temp != NULL)
    {
        temp2->random = mapping[temp->random];

        temp = temp->next;
        temp2 = temp2->next;
    }

    return clonehead;
}

int main()
{

    return 0;
}