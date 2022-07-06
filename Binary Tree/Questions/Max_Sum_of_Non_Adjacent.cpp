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

pair<int, int> solve(Node* root)
{
    if(root==NULL)
        return {0,0};
    
    pair<int,int> lt = solve(root->left);
    pair<int,int> rt = solve(root->right);


    pair<int,int> res;

    res.first = root->data+lt.second + rt.second;
    res.second = max(lt.first, lt.second) + max(rt.second,rt.first);
    return res;
}

int getMaxSum(Node* root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout<<getMaxSum(root)<<endl;
    return 0;
}