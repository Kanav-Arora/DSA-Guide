#include <iostream>
using namespace std;

class Node
{
public:
    int row;
    int col;
    int data;
    Node *next;

    Node(int r, int c, int val)
    {
        row = r;
        col = c;
        data = val;
        next = NULL;
    }
};

void insert(Node* &root, int row, int col, int data)
{
    if (root == NULL)
    {
        Node *n = new Node(row, col, data);
        root = n;
    }

    Node *temp = root;

    while (temp->next != NULL)
        temp = temp->next;

    Node *n = new Node(row, col, data);
    temp->next = n;
}

void printList(Node *row)
{
    Node *ptr = row;
    cout << "row_position:";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "column_position:";

    ptr = row;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:";
    ptr = row;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int sparseMatrix[4][5] = {{0, 0, 3, 0, 4},
                              {0, 0, 5, 7, 0},
                              {0, 0, 0, 0, 0},
                              {0, 2, 6, 0, 0}};
    Node *root = NULL;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix[i][j] != 0)
                insert(root, i, j,
                    sparseMatrix[i][j]);
        }
    }
    printList(root);
    return 0;
}