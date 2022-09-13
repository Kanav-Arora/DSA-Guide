#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    int indegree[V] = {0};

    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        topo.push_back(front);
        for (auto i : adj[front])
        {
            indegree[i]--;

            if (indegree[i] == 0)
                q.push(i);
        }
    }

    return topo;
}

int main()
{

    return 0;
}