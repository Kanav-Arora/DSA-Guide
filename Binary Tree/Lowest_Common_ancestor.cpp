#include<iostream>
#include<algorithm>
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

bool getPath(Node* root, int n, vector<int> &path)
{

    if(root==NULL)
        return false;

    if(root->data==n)
    {
        path.push_back(root->data);
        return true;
    }

    bool leftp = getPath(root->left, n, path);
    bool rightp = getPath(root->right, n, path);

    if(leftp==true || rightp == true)
    {
        path.push_back(root->data);
        return true;
    }

    return false;
}

int LCA(Node* root, int n1, int n2)
{
    vector<int> path1, path2;

    if(!getPath(root,n1, path1) || !getPath(root, n2, path2))
        return -1;

    int pc;

    reverse(path1.begin(), path1.end());
    reverse(path2.begin(), path2.end());

    for(pc=0; pc<path1.size() && path2.size(); pc++)
        if(path1[pc] != path2[pc])
            return path1[pc-1];

    return -1;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->left->left = new Node(7);
    root->right->right = new Node(6);


    cout<<LCA(root, 5, 6);
    return 0;
}