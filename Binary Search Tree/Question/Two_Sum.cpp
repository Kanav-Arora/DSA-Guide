#include<iostream>
#include<queue>
#include<vector>
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

void inOrder(Node* root, vector<int> &v)
{
    if(root==NULL)
        return;

    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}

pair<int, int> TwoSum(Node* root, int target)
{
    vector<int> v;
    inOrder(root, v);

    int i = 0;
    int j = v.size()-1;

    while(i<j)
    {
        int sum = v[i] + v[j];

        if(sum==target)
            return {v[i],v[j]};
        
        if(sum>target)
            j--;
        
        if(sum<target)
            i++;
    }

    return {-1,-1};
}

int main()
{
    Node* root = NULL;
    input(root);
    // 10 7 15 5 9 17 16 19 -1

    int target;
    cin>>target;
    pair<int, int> ans = TwoSum(root, target);

    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}