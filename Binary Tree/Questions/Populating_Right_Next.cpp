#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;
        Node* next;

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

//Leetcode : 116

Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        
        if(root->left)
            root->left->next = root->right;
        if(root->right && root->next!=NULL)
            root->right->next = root->next->left;
        if(root->right && root->next==NULL)
            root->right->next = NULL;
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}