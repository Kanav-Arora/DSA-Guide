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


int height(Node* root)
{
    if(root==NULL)
        return 0;
    return max(height(root->right),height(root->left))+1;
}

bool BalancedHeight(Node* root)
{
    if(root==NULL)
        return true;

    if(BalancedHeight(root->left)==false || BalancedHeight(root->right)==false)
        return false;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1)
        return true;
    
    return false;

}

pair<bool, int> BalancedHeightModified(Node* root)
{
    if(root==NULL)
        return {true,0};
    
    pair<bool, int> left = BalancedHeightModified(root->left);
    pair<bool, int> right = BalancedHeightModified(root->right);

    int lh = left.second;
    int rh = right.second;

    int diff = abs(lh-rh);

    int height = max(lh,rh) + 1;

    if(left.first && right.first && diff<=1) 
    {
        return {true,height};
    }

    return {false,height};
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);

    cout<<BalancedHeightModified(root).first<<endl;
    return 0;
}