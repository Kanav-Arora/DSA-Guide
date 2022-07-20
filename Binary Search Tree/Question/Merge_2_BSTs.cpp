#include<iostream>
#include<queue>
#include<algorithm>
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


// Approach: 1

void InOrder(Node* root, vector<int> &v)
{
    if(root==NULL)
        return;
    
    InOrder(root->left, v);
    v.push_back(root->data);
    InOrder(root->right,v);
}

vector<int> mergeVectors(vector<int> v1, vector<int> v2)
{
    int ptr1 = v1.size()-1;
    int ptr2 = v2.size()-1;

    vector<int> v;

    while(ptr1>=0 && ptr2>=0)
    {
        if(v1[ptr1]>v2[ptr2])
        {
            v.push_back(v1[ptr1]);
            ptr1--;
        }    

        else
        {
            v.push_back(v2[ptr2]);
            ptr2--;
        }
    }  

    while(ptr1>=0)
    {
        v.push_back(v1[ptr1]);
        ptr1--;
    }

    while(ptr2>=0)
    {
        v.push_back(v2[ptr2]);
        ptr2--;
    }

    reverse(v.begin(),v.end());
    return v;
}

Node* vectorToBST(vector<int> v, int s, int e)
{
    if(s>e)
        return NULL;

    int mid = s + (e-s)/2;
    Node* root = new Node(v[mid]);

    root->left = vectorToBST(v, s, mid-1);
    root->right = vectorToBST(v, mid+1, e);

    return root;
}

Node* Merge1(Node* root1, Node* root2)
{
    vector<int> v1;
    vector<int> v2;

    InOrder(root1,v1);
    InOrder(root2,v2);

    vector<int> v = mergeVectors(v1, v2);

    return vectorToBST(v, 0, v.size()-1);
}

// Approach 2

void ConvertIntoLL(Node* root, Node* &prev)
{
    if(root==NULL)
        return;

    ConvertIntoLL(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    ConvertIntoLL(root->right, prev);
}

Node* MergeLL(Node* root1, Node* root2)
{
    Node* head = NULL;
    Node* tail = NULL;

    while(root1!=NULL && root2!=NULL)
    {
        if(root1->data<root2->data)
        {
            if(head==NULL)
            {
                head= root1;
                tail = root1;
                root1 = root1->right;
            }
            else
            {
                tail->right = root1;
                tail = root1;
                root1 = root1->right;
            }
        }
        else
        {
            if(head==NULL)
            {
                head = root2;
                tail = root2;
                root2 = root2->right;
            }
            else
            {
                tail->right = root2;
                tail = root2;
                root2 = root2->right;
            }
        }
    }

    while(root1!=NULL)
    {
        tail->right = root1;
        tail = root1;
        root1 = root1->right;
    }

    while(root2!=NULL)
    {
        tail->right = root2;
        tail = root2;
        root2 = root2->right;        
    }

    return head;
}

int CountNodes(Node* root)
{
    int cnt = 0;
    Node* temp = root;
    
    while(temp!=NULL)
    {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

Node* LLToBST(Node* head, int n)
{
    if(n<=0 || head==NULL)
        return NULL;

    Node* lt = LLToBST(head, n/2);
    Node* root = head;
    root->left = lt;
    head = head->right;
    root->right = LLToBST(head, n/2-1);

    return root;
}

Node* Merge2(Node* root1, Node* root2)
{
    Node* dummy1 = new Node(-1);
    Node* dummy2 = new Node(-1);

    Node* prev = dummy1;
    ConvertIntoLL(root1, prev);

    prev = dummy2;
    ConvertIntoLL(root2, prev);

    root1 = dummy1->right;
    root2 = dummy2->right;
    delete dummy1;
    delete dummy2;

    Node* mergedLL = MergeLL(root1, root2);

    while(mergedLL!=NULL)
    {
        cout<<mergedLL->data<<" ";
        mergedLL = mergedLL->right;
    }
    cout<<endl;

    return root1;

    // return LLToBST(mergedLL, CountNodes(mergedLL));
}

int main()
{
    Node* root1 = new Node(15);
    root1->left = new Node(10);
    root1->left->left = new Node(5);
    root1->left->right = new Node(12);
    root1->right = new Node(20);
    root1->right->left = new Node(18);
    root1->right->right = new Node(22);

    printBT(root1);

    Node* root2 = NULL;
    root2 = new Node(10);
    root2->left = new Node(8);
    root2->left->left = new Node(4);
    root2->left->left->left = new Node(2);
    root2->right = new Node(12);
    root2->right->right = new Node(16);
    root2->right->right->right = new Node(20);

    printBT(root2);

    Node* root = Merge2(root1, root2);

    // printBT(root);

    return 0;
}