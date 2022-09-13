#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    if (!node)
        return NULL;

    unordered_map<Node *, Node *> mp;
    Node *copy = new Node(node->val);
    mp[node] = copy;

    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        for (auto i : front->neighbors)
        {
            if (mp.find(i) == mp.end())
            {
                Node *n = new Node(i->val);
                q.push(i);
                mp[i] = n;
            }

            mp[front]->neighbors.push_back(mp[i]);
        }
    }

    return copy;
}

int main()
{

    return 0;
}