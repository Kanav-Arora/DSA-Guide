// Use of Kahn's algorithm

#include <iostream>
#include<queue>
#include<vector>
using namespace std;

bool isCyclic(int V, vector<int> adj[])
{
    int indegree[V] = {0};

    for (int i = 0; i < V; i++)
    {
        for (auto k : adj[i])
        {
            indegree[k]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    if (q.size() == 0)
        return true;

    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        count++;
        q.pop();

        for (auto i : adj[front])
        {
            indegree[i]--;

            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (count != V)
        return true;

    return false;
}

int main()
{

    return 0;
}