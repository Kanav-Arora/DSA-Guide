#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;
        Node* parent;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

/*
    Leetcode: 1650

    Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).
    Each node will have a reference to its parent node. The definition for Node is below:


    class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
    }   
*/

Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p, *b = q;
        while (a != b) {
            a = (a == NULL ? q : a->parent);
            b = (b == NULL ? p : b->parent);
        }
        return a;
    }

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}