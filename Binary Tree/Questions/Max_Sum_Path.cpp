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

int solve(Node* root, int &ans)
{
    if(root==NULL)
    {
        return 0;
    }

    if(root->right==NULL && root->left==NULL)       // leaf node
    {
        ans = max(ans, root->data);
        return root->data;
    }

    int leftans = solve(root->left, ans);
    int rightans = solve(root->right, ans);

    int nodemax = max(max(root->data, root->data+leftans+rightans), 
                    max(root->data+leftans, root->data+rightans));
    
    ans = max(ans, nodemax);

    int singlePathSum = max(root->data, max(root->data+leftans, root->data+rightans));

    return singlePathSum;

}

int MaxSumPath(Node* root)
{
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->right = new Node(5);
    // root->right->right = new Node(-6);

    cout<<MaxSumPath(root)<<endl;
    return 0;
}