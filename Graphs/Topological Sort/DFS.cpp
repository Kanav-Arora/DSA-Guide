#include <iostream>
#include<vector>
#include<stack>
using namespace std;

void sorting(int i, int v, vector<int> adj[], vector<bool> &vis, stack<int> &s)
{
    vis[i] = true;

    for (auto k : adj[i])
    {
        if (!vis[k])
        {

            sorting(k, v, adj, vis, s);
        }
    }

    s.push(i);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> s;
    vector<int> ans;

    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            sorting(i, V, adj, vis, s);
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{

    return 0;
}