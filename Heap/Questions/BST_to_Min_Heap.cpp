#include<iostream>
#include<queue>
using namespace std;

class Node
{
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

Node* insert(Node* root, int data)
{
    if(root==NULL)
    {
        return new Node(data);
    }
    
    if(data>root->data)
        root->right = insert(root->right, data);

    else
        root->left = insert(root->left, data);

    return root;
}

void input(Node* &root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root = insert(root,data);
        cin>>data;
    }
}

void printLevelOrder(Node* root)
{
    if(root==NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL)
        {
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);

        }
        else if(!q.empty())
        {
            q.push(NULL);
        }

    }
    cout<<endl;
}

void InOrderToArray(Node* root, vector<int> &v)
{
    if(root==NULL)
        return;
    
    InOrderToArray(root->left, v);
    v.push_back(root->data);
    InOrderToArray(root->right, v);
}

void TreetoHeap(Node* root, vector<int> inOrder, int &index)
{
    if(root==NULL)
        return;
    
    root->data = inOrder[index];
    index++;

    TreetoHeap(root->left, inOrder, index);
    TreetoHeap(root->right, inOrder, index);
}

void BSTtoHeapUtil(Node* root)
{
    vector<int> inOrder;
    InOrderToArray(root, inOrder);

    int index = 0;
    TreetoHeap(root, inOrder, index);
}

int main()
{
    Node* root = NULL;
    input(root);
    // Test Case I/P: 4 2 6 1 3 5 7 -1
    // Output:
    // 4 2 6 1 3 5 7 
    // 1 2 5 3 4 6 7 

    printLevelOrder(root);
    BSTtoHeapUtil(root);
    printLevelOrder(root);

    return 0;
}