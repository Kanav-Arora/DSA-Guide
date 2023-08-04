#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

vector<int> VertcialTraversal(Node* root)
{
    map<int, map<int, vector<int> > > nodes;          // map<hd, <level, vector>>

    queue<pair<Node*, pair<int,int> > > q;            // queue<Node*, hd, level>
    vector<int> ans;

    if(root==NULL)
        return ans;

    
    q.push({root,{0,0}});
    while(!q.empty())
    {
        pair<Node*, pair<int, int> > val = q.front();
        q.pop();

        Node* frontNode = val.first;
        int hd = val.second.first;
        int level = val.second.second;

        nodes[hd][level].push_back(frontNode->data);

        if(frontNode->left)
            q.push({frontNode->left, {hd-1, level+1}});
        
        if(frontNode->right)
            q.push({frontNode->right, {hd+1, level+1}});
    }

    for(auto i: nodes)
    {
        for(auto j :  i.second)
        {
            for(auto k: j.second)
            {
                ans.push_back(k);
            }
        }
    }

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
    root->right->left->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    vector<int> ans = VertcialTraversal(root);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}