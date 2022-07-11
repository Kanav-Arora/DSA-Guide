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

pair<bool,int> Balanced(Node* root)
{
    if(root==NULL)
        return {true,0};

    pair<bool,int> lt = Balanced(root->left);
    pair<bool,int> rt = Balanced(root->right);

    if(lt.first && rt.first && abs(lt.second-rt.second)<=1)
        return {true, 1+max(lt.second, rt.second)};
    
    return {false, 1+max(lt.second, rt.second)};
}

void inorder(Node* root, vector<int> &v)
{
    if(root==NULL)
        return;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right,v);
}

Node* inordertoBST(vector<int> v, int start, int end)
{
    if(start>end)
        return NULL;

    int mid = (start+end)/2;

    Node* root = new Node(v[mid]);

    root->left = inordertoBST(v,start,mid-1);
    root->right = inordertoBST(v,mid+1,end);

    return root;
}

Node* NormaltoBalanced(Node* root)
{
    vector<int> v;
    inorder(root,v);
    return inordertoBST(v,0,v.size()-1);
}

int main()
{
    Node* root = NULL;
    // input(root);
    // 10 7 15 5 9 17 16 19 -1

    root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->left->left = new Node(2);
    root->right = new Node(12);
    root->right->right = new Node(16);
    root->right->right->right = new Node(20);


    cout<<Balanced(root).first<<endl;

    root = NormaltoBalanced(root);

    cout<<Balanced(root).first<<endl;

    return 0;
}