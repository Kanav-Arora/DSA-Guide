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

Node* MinVal(Node* root)
{
    Node* temp = root;

    while(temp->left!=NULL)
        temp = temp->left;
    
    return temp;
}

Node* deleteFromBST(Node* root, int val)
{
    if(root==NULL)
        return NULL;
    
    if(val==root->data)
    {

        // 1 child

        if(root->left && !root->right)
        {
            Node* child = root->left;
            delete root;
            return child;
        }

        else if(root->right && !root->left)
        {
            Node* child =  root->right;
            delete root;
            return child;
        }

        // 2 child
        else if(root->left && root->right)
        {
            int mini = MinVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }


        // 0 child
        else 
        {
            delete root;
            return NULL;
        }
    }

    else if(val>root->data)
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }

    else
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
}

int main()
{
    Node* root = NULL;
    input(root);

    int val;
    cin>>val;

    printLevelOrder(root);

    // 10 7 15 5 9 17 16 19 -1

    deleteFromBST(root, val);

    printLevelOrder(root);
    

    return 0;
}