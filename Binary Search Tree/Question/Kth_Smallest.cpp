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

int KthSmallest(Node* root, int &i, int k)
{
    if(root==NULL)
        return -1;

    int left = KthSmallest(root->left,i, k);

    if(left!=-1)
        return left;

    i++;

    if(i==k)
        return root->data;

    int right = KthSmallest(root->right,i, k);

    if(right!=-1)
        return right;

    return -1;
}

int Morris(Node* root, int k)
{
    int i = 0;

    Node* curr = root;

    while(curr)
    {
        if(!curr->left)
        {
            i++;
            if(i==k)
                    return curr->data;
            curr = curr->right;
        }

        else
        {
            Node* temp = curr->left;

            while(temp->right && temp->right!=curr)
                temp = temp->right;

            if(temp->right==NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }

            if(temp->right==curr)
            {
                temp->right = NULL;
                i++;
                if(i==k)
                    return curr->data;
                curr = curr->right;
            }
        }

    }

    return -1;

}

int main()
{
    Node* root = NULL;
    input(root);
    // 10 7 15 5 9 17 16 19 -1

    cout<<root->data<<endl;

    cout<<Morris(root,3)<<endl;
    return 0;
}