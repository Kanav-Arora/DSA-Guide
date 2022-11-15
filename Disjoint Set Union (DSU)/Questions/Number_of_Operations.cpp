#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);

        int extras = 0;
        for (auto i : edge)
        {
            int u = i[0];
            int v = i[1];

            if (ds.find(u) == ds.find(v))
                extras++;

            else
                ds.unionBySize(u, v);
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                count++;
        }

        if (extras < count - 1)
            return -1;

        return count - 1;
    }
};

int main()
{

    return 0;
}