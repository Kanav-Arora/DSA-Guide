#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

// Leetcode : 107.

/*
    Level Order traversal of a BT from bottom to up.

    Input: root = [3,9,20,null,null,15,7]
    Output: [[15,7],[9,20],[3]]
*/

vector<vector<int>> levelOrderBottom(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++)
            {
                Node* frontnode = q.front();
                q.pop();
                temp.push_back(frontnode->data);
                
                if(frontnode->left)
                    q.push(frontnode->left);
                if(frontnode->right)
                    q.push(frontnode->right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}