#include<iostream>
#include<vector>
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

void leftPath(Node* root, vector<int> &path)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;

    path.push_back(root->data);

    if(root->left)
        leftPath(root->left, path);
    else
        leftPath(root->right, path);
}

void leafPath(Node* root, vector<int> &path)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
    {
        path.push_back(root->data);
        return;
    }

    leafPath(root->left, path);
    leafPath(root->right, path);
}

void rightPath(Node* root, vector<int> &path)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;

    if(root->right)
        rightPath(root->right, path);
    else
        rightPath(root->left, path);

    path.push_back(root->data);
}

vector<int> BoundaryTraversal(Node* root)
{
    vector<int> path;
    if(root==NULL)
        return path;

    path.push_back(root->data);

    leftPath(root->left, path);
    leafPath(root->left, path);
    leafPath(root->right, path);
    rightPath(root->right, path);

    return path;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->left->left = new Node(3);

    root->right = new Node(4);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);
    root->right->right->right->left = new Node(10);
    root->right->right->right->right = new Node(11);

    vector<int> ans = BoundaryTraversal(root);

    for(auto i : ans)
        cout<<i<<" ";
    
    cout<<endl;

    return 0;
}   