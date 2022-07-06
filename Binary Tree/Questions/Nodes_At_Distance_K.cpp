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


//case 1 code
void printSubtree(Node* root, int k)
{
    if(root==NULL || k<0)
        return;

    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }

    printSubtree(root->left,k-1);
    printSubtree(root->right,k-1);
}

//case 2 code

int printNodesAtK(Node* root, int target, int k)
{
    if(root==NULL)      // target node not found
        return -1;

    if(root->data==target)
    {
        printSubtree(root,k);
        return 0;
    }

    int dl = printNodesAtK(root->left, target, k);
    int dr = printNodesAtK(root->right, target, k);

    if(dl!=-1)
    {
        if(dl+1==k)
            cout<<root->data<<" ";

        else
            printSubtree(root->right,k-dl-2);

        return 1+dl;
    }

    if(dr!=-1)
    {
        if(dr+1==k)
            cout<<root->data<<" ";

        else
            printSubtree(root->left,k-dr-2);

        return 1+dr;
    }

    return -1;
}



int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}