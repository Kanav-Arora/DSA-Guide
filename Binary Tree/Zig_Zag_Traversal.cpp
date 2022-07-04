#include<iostream>
#include<vector>
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

vector<int> ZigZag(Node* root)
{
    vector<int> ans;

    if(root==NULL)
        return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty())
    {
        int size = q.size();

        vector<int> temp(size);

        for(int i=0; i<size; i++)
        {
            Node* frontnode = q.front();
            q.pop();

            int index  = leftToRight ? i : size-i-1;

            temp[index] = frontnode->data;

            if(frontnode->left)
                q.push(frontnode->left);
            
            if(frontnode->right)
                q.push(frontnode->right);

        }

        leftToRight = !leftToRight;

        for(auto i: temp)
            ans.push_back(i);
    }

    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<int> ans = ZigZag(root);

    for(auto i : ans)
        cout<<i<<" ";
    return 0;
}