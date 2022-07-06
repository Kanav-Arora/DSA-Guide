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



void solve(Node* root, int k, int &count, vector<int> &path)
{
    if(root==NULL)
    {
        return;
    }

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int size = path.size();

    int sum=0;

    for(int i=size-1; i>=0; i--)
    {
        sum+=path[i];

        if(sum==k)
            count++;
    }

    path.pop_back();
}

int KSumPath(Node* root, int k)
{
    int count = 0;
    vector<int> path;
    solve(root, k, count, path);

    return count;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(1);
    root->right = new Node(1);

    cout<<KSumPath(root, 2);
    return 0;
}