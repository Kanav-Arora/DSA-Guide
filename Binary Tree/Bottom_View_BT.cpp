#include<iostream>
#include<vector>
#include<map>
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

vector<int> BottomView(Node* root)
{
    map<int, int> lowerNode;

    queue<pair<Node*, int> >  q;
    vector<int> ans;

    if(root==NULL)
        return ans;
    
    q.push({root,0});

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        lowerNode[hd] = frontNode->data;

        if(frontNode->left)
            q.push({frontNode->left, hd-1});

        if(frontNode->right)
            q.push({frontNode->right, hd+1}); 
    }

    for(auto i: lowerNode)
        ans.push_back(i.second);

    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = BottomView(root);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}   