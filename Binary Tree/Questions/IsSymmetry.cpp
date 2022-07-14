#include<iostream>
#include<queue>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            data = data;
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

/*
    Binary Tree is symmetrical if it is a mirror image

    Leetcode: 101.
*/

//iterative solution

bool isSymmetric(Node* root) {
        Node* curr = root;
        queue<Node*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty())
        {
            Node* l = q.front();
            q.pop();
            Node* r = q.front();
            q.pop();
            
            if(!l && !r)
                continue;
            
            if(!l || !r)
                return false;
            
            if(l->data!=r->data)
                return false;
            
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }        
        return true;
}

// Recursive

bool helper(Node* lt, Node* rt)
{
    if(lt==NULL && rt==NULL)
        return true;
    
    if(lt==NULL || rt==NULL)
        return false;

    return helper(lt->left, rt->right) && helper(lt->right, rt->left);
}

bool isSymmetricRecursive(Node* root)
{
    return helper(root->left, root->right);
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}