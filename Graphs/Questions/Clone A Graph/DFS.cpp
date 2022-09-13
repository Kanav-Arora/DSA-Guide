#include <iostream>
#include <vector>
#include <unordered_map>
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

void DFS(Node *node, unordered_map<Node *, Node *> &mp)
{
    for (auto i : node->neighbors)
    {
        if (mp.find(i) == mp.end())
        {
            Node *n = new Node(i->val);
            mp[i] = n;
            DFS(i, mp);
        }

        mp[node]->neighbors.push_back(mp[i]);
    }
}

Node *cloneGraph(Node *node)
{
    if (!node)
        return NULL;

    unordered_map<Node *, Node *> mp;
    Node *copy = new Node(node->val);
    mp[node] = copy;

    DFS(node, mp);

    return copy;
}

int main()
{

    return 0;
}