#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int a) { return parent[a] == a ? a : find(parent[a]); }

void unite(int a, int b) { parent[find(b)] = find(a); }

int numProvinces(vector<vector<int>> adj, int V)
{
    for (int i = 0; i < V; i++)
        parent.push_back(i);

    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[0].size(); j++)
        {
            if (adj[i][j] == 1)
                unite(i, j);
        }
    }

    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (parent[i] == i)
            count++;
    }

    return count;
}

int main()
{

    return 0;
}