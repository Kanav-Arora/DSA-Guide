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

int Height(Node* node)
{
    if(node==NULL)
        return 0;

    return max(Height(node->left),Height(node->right)) + 1;
}

int diameterBT(Node* root)                  // O(N^2)
{
    if(root==NULL)
        return 0;

    int lefth = Height(root->left);
    int righth = Height(root->right);

    int currdia = lefth + righth + 1;

    int leftdia = diameterBT(root->left);
    int rightdia = diameterBT(root->right);

    return max(currdia, max(leftdia, rightdia));
}

int modifiedDiameterBT(Node* root, int* height)
{
    if(root==NULL)
    {
        *height = 0;
        return 0;
    }


    int lh =0, rh =0;
    int ldia = modifiedDiameterBT(root->left, &lh);
    int rdia = modifiedDiameterBT(root->right, &rh);

    int currdia = lh + rh +1;

    *height = max(lh,rh) + 1;


    return max(currdia, max(ldia, rdia));

}

pair<int,int> modifiedBT2(Node* root)
{
    if(root==NULL)
    {
        return {0,0};
    }

    pair<int,int> leftdia = modifiedBT2(root->left);
    pair<int,int> rightdia = modifiedBT2(root->right);

    int op1 = leftdia.first;
    int op2 = rightdia.first;

    int op3 = leftdia.second + rightdia.second + 1;

    return {max(op1, max(op2,op3)), max(leftdia.second,rightdia.second)+1};
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);


    int height = 0;
    cout<<diameterBT(root)<<endl;
    cout<<modifiedDiameterBT(root, &height)<<endl;
    return 0;
}