#include<iostream>
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

void Mapping(Node* root, map<Node*, Node*> &parentNode, map<Node*, bool> &visited)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
    {
        visited[root] = false;
        return;
    }
    
    visited[root] = false;
    if(root->left)
    parentNode[root->left] = root;
    
    if(root->right)
    parentNode[root->right] = root;

    Mapping(root->left,parentNode, visited);
    Mapping(root->right,parentNode, visited);
}

Node* FindNode(Node* root, int t)
{
    if(root==NULL)
        return NULL;
    
    if(root->data==t)
        return root;

    Node* lt = FindNode(root->left, t);
    Node* rt = FindNode(root->right, t);

    if(lt!=NULL)
        return lt;
    
    if(rt!=NULL)
        return rt;

    return NULL;
}

int BurnTree(Node* root, int t)
{
    map<Node*, Node*> parentNode;
    map<Node*, bool> visited;
    Mapping(root, parentNode, visited);
    parentNode[root] = NULL;

    Node* target = FindNode(root, t);
    queue<Node*> q;
    q.push(target);
    visited[target] =1;

    bool addition = false;
    int time = 0;

    while(!q.empty())
    {
        int size = q.size();
        addition = false;
        for(int i=0; i<size; i++)
        {
            Node* frontNode = q.front();
            q.pop();
            if(frontNode->left!=NULL && visited[frontNode->left]==false)
            {
                visited[frontNode->left] = true;
                q.push(frontNode->left);
                addition = true;
            }

            if(frontNode->right!=NULL && visited[frontNode->right]==false)
            {
                visited[frontNode->right] = true;
                q.push(frontNode->right);
                addition = true;
            }

            if(parentNode[frontNode]!=NULL && visited[parentNode[frontNode]]==false)
            {
                visited[parentNode[frontNode]] = true;
                q.push(parentNode[frontNode]);
                addition = true;
            }
        }

        if(addition==true)
        {
            time++;
        }
    }

    return time;
}

int main()
{
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);
    root->right->right->right->right = new Node(5);

    cout<<BurnTree(root, 4)<<endl;
    return 0;
}