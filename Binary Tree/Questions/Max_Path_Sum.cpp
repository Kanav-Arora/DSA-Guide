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

int maxPathUtil(Node* root, int ans)
{
    if(root==NULL)
        return 0;
    
    int left = maxPathUtil(root->left, ans);
    int right = maxPathUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data+left+right), max(root->data+left, root->data+right));

    ans = max(nodeMax, ans);
    int singlePathSum = max(root->data, root->data + left + right);


    return ;
}

int MaxPathSum(Node* root)
{
    int ans = INT_MIN;

    maxPathUtil(root, ans);

    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}