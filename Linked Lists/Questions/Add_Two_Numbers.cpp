/*

    Interview Question:

    Add two number represented by a LL

    Add 1 to a number represented by a LL

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
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

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *AddTwoNumbers(Node *head1, Node *head2)
{
    Node *new_head1 = reverse(head1);
    Node *new_head2 = reverse(head2);

    Node *f = new_head1;
    Node *s = new_head2;

    Node *head = NULL;
    int carry = 0;
    int sum = 0;

    while (f != NULL && s != NULL)
    {
        sum = (f->data + s->data + carry) % 10;
        carry = (f->data + s->data + carry) / 10;
        InsertAtTail(head, sum);

        f = f->next;
        s = s->next;
    }

    while (f != NULL)
    {
        sum = (f->data + carry) % 10;
        carry = (f->data + carry) / 10;
        InsertAtTail(head, sum);

        f = f->next;
    }

    while (s != NULL)
    {
        sum = (s->data + carry) % 10;
        carry = (s->data + carry) / 10;
        InsertAtTail(head, sum);

        s = s->next;
    }

    while (carry)
    {
        sum = carry % 10;
        carry = carry / 10;

        InsertAtTail(head, sum);
    }

    return reverse(head);
}

int main()
{
    Node *head1 = NULL;
    InsertAtTail(head1, 1);
    InsertAtTail(head1, 2);
    InsertAtTail(head1, 3);

    Node *head2 = NULL;
    InsertAtTail(head2, 4);
    InsertAtTail(head2, 5);

    Node *head = AddTwoNumbers(head1, head2);

    display(head);

    return 0;
}