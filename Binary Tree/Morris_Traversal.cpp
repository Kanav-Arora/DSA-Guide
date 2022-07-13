#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        data = data;
        left = NULL;
        right = NULL;
    }
};

void printBT(const std::string &prefix, const Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        std::cout << node->data << std::endl;
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBT(const Node *node)
{
    printBT("", node, false);
}

vector<int> InOrder(Node *root)
{
    vector<int> ans;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }

        else
        {
            Node *temp = curr->left;
            while (temp->right && temp->right != curr)
                temp = temp->right;

            if (!temp->right)
            {
                temp->right = curr;
                curr = curr->left;
            }

            else
            {
                temp->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

vector<int> PreOrder(Node *root)
{
    vector<int> ans;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }

        else
        {
            Node *temp = curr->left;
            while (temp->right && temp->right != curr)
                temp = temp->right;

            if (!temp->right)
            {
                temp->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            }

            else
            {
                temp->right = NULL;
                curr = curr->right;
            }
        }
    }

    return ans;
}

vector<int> PostOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    Node *curr = root;
    while (curr)
    {
        if (curr->right == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->left;
        }
        else
        {
            Node *temp = curr->right;
            while (temp->left && temp->left != curr)
                temp = temp->left;

            if (temp->left == NULL)
            {
                temp->left = curr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                temp->left = NULL;
                curr = curr->left;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}