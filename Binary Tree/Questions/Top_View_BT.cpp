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

vector<int> TopView(Node* root)
{
    map<int, map<int, int > > nodes;

    queue<pair<Node*, pair<int, int> > > q;

    vector<int> ans;
    if(root==NULL)
        return ans;

    q.push({root,{0,0}});

    while(!q.empty())
    {
        pair<Node* , pair<int, int> >  temp = q.front();

        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        if(nodes.find(hd)==nodes.end() || nodes[hd].find(level)==nodes[hd].end())
            nodes[hd][level] = frontNode->data;
        
        if(frontNode->left)
            q.push({frontNode->left,{hd-1, level+1}});
        
        if(frontNode->right)
            q.push({frontNode->right, {hd+1, level+1}});
    }

    for(auto i : nodes)
    {
        ans.push_back(i.second.begin()->second);
    }

    return ans;
}  


vector<int> TopView2(Node* root)
{
    vector<int> ans;

    map<int, int> TopNode;

    queue<pair<Node*, int> >  q;
    
    if(root==NULL)
        return ans;

    q.push({root, 0});          // queue-> root,hd


    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if(TopNode.find(hd)==TopNode.end())
            TopNode[hd] = frontNode->data;
        
        if(frontNode->left)
            q.push({frontNode->left, hd-1});
        
        if(frontNode->right)
            q.push({frontNode->right, hd+1});
    }

    for(auto i: TopNode)
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
    root->right->left->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    vector<int> ans = TopView2(root);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}