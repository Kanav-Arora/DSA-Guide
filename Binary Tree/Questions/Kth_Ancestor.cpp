#include<iostream>
#include<climits>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

void printBT(const std::string& prefix, const Node* node, bool isLeft)
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

void printBT(const Node* node)
{
    printBT("", node, false);
}

Node* KthAncestor(Node* root,int n, int &k)
{
    if(root==NULL)
        return NULL;

    if(root->data==n)
        return root;

    Node* leftNode = KthAncestor(root->left, n, k);
    Node* rightNode = KthAncestor(root->right, n, k);

    if(leftNode!=NULL && rightNode==NULL)
    {
        k--;
        if(k<=0)
        {
            k==INT_MAX;
            return root;
        }

        return leftNode;
    }

    if(leftNode==NULL && rightNode!=NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }

        return rightNode;
    }

    return NULL;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    int k=2;
    cout<<KthAncestor(root, 4,k)->data;
    return 0;
}   