#include<iostream>
#include<queue>
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

int RightViewUsingQueue(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        for(int i =0; i<n; i++)
        {
            Node* curr = q.front();
            q.pop();

            if(i==n-1)
                cout<<curr->data<<" ";
            

            if(curr->left!=NULL)
                q.push(curr->left);

            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}

void RightViewRecursion(Node* root, vector<int> &ans, int level)
{
    if(root==NULL)
        return;

    if(level==ans.size())
        ans.push_back(root->data);

    if(root->right)
        RightViewRecursion(root->right, ans, level+1);
    
    if(root->left)
        RightViewRecursion(root->left, ans, level+1);
    
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

    RightViewUsingQueue(root);
    cout<<endl;

    vector<int> ans;
    RightViewRecursion(root, ans, 0);

    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}