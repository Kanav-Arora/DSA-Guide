#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> adjrev[V];
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto k : adj[i])
        {
            adjrev[k].push_back(i);
            indegree[i]++;
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

    vector<int> ans;

    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();

        for (auto k : adjrev[front])
        {
            indegree[k]--;

            if (indegree[k] == 0)
                q.push(k);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}