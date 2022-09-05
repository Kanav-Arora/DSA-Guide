// Question is related to connected components of Graph theory
// GFG: Number of Provinces

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> vertices[], int target, vector<bool> &visited)
{
    visited[target] = 1;
    for (auto i : vertices[target])
    {
        if (visited[i] == 0)
        {
            DFS(vertices, i, visited);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    vector<int> adjL[V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjL[i].push_back(j);
                adjL[j].push_back(i);
            }
        }
    }

    vector<bool> visited(V, 0);
    int counter = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            counter++;
            DFS(adjL, i, visited);
        }
    }

    return counter;
}

int main()
{

    return 0;
}