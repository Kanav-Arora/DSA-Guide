/*
    Sum of left subtree and right subtree is equal to value of current node. True if this is valid for all nodes.

*/

#include<iostream>
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

pair<bool, int> SumTree(Node* root)
{
    if(root==NULL)
        return {true,0};

    if(root->left==NULL && root->right==NULL)
        return {true,root->data};
    
    pair<bool, int> leftsub = SumTree(root->left);
    pair<bool, int> rightsub = SumTree(root->right);

    if(leftsub.first && rightsub.first && root->data == (leftsub.second + rightsub.second))
        return {true, root->data + leftsub.second + rightsub.second};
    
    return {false, root->data + leftsub.second + rightsub.second};
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(10);
    root->right = new Node(30);

    cout<<SumTree(root).first<<endl;
    return 0;
}