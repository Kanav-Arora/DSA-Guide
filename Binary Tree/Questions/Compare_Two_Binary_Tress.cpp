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

bool compareTwo(Node* root1, Node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;

    if(root1==NULL && root2!=NULL || (root1!=NULL && root2==NULL))
        return false;

    bool left = compareTwo(root1->left, root2->left);
    bool right = compareTwo(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value)
        return 1;
    
    return 0;
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(6);
    // root1->right->left = new Node(4);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    cout<<compareTwo(root1,root2);
    return 0;
}