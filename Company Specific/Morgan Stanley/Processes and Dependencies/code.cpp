#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &nodes, int child)
{
    if (nodes[child] == child)
        return child;

    return find(nodes, nodes[child]);
}

void u(vector<int> &nodes, vector<int> &size, vector<int> &priority, int u, int v)
{
    int par = find(nodes, u);
    nodes[v] = par;
    size[par]++;
    priority[par] += priority[v];
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<int> nodes(n + 1, 0);
    vector<int> size(n + 1, 1);
    for (int i = 1; i <= n; i++)
        nodes[i] = i;
    vector<pair<int, int>> d(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        d[i] = {u, v};
    }
    vector<int> priority(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> priority[i];
    }

    for (int i = 0; i < m; i++)
    {
        u(nodes, size, priority, d[i].first, d[i].second);
    }
    size[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (nodes[i] != i)
            size[i] = -1;
    }

    int maxi = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (priority[i] > maxi)
        {
            maxi = priority[i];
            ans = size[i];
        }
    }

    cout << ans << endl;
    return 0;
}

/*

6 3
1 2
2 3
4 5
11 2 3 15 8 22

*/