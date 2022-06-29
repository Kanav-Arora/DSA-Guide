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

Node* LCA(Node* root, int n1, int n2)
{
    if(root==NULL)
        return NULL;

    if(root->data==n1 || root->data==n2)
        return root;

    Node* leftlca = LCA(root->left, n1, n2);
    Node* rightlca = LCA(root->right, n1, n2);

    if(leftlca!=NULL && rightlca!=NULL)
        return root;
    
    if(leftlca==NULL)
        return rightlca;
    
    if(rightlca==NULL)
        return leftlca;
}

int distance(Node* root, int n, int dist)
{
    if(root==NULL)
        return -1;

    if(root->data==n)
        return dist;

    int left = distance(root->left, n, dist+1);
    
    if(left!=-1)
        return left;
    
    return distance(root->right, n, dist+1);
    
}

int shortestDistance(Node* root, int n1, int n2)
{
    Node* lca = LCA(root, n1, n2);

    int d1 = distance(lca, n1,0);
    int d2 = distance(lca, n2,0);

    return d1+d2;
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


    cout<<shortestDistance(root, 4,3);
    return 0;
}