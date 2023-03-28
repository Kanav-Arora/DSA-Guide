#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define INT_MAX 1e9
int n = 4;
int dp[16][4];
int VISITED_ALL = (1 << n) - 1;
vector<vector<int>> adj(n, vector<int>(n, 0));
int src;

inline int min(int a, int b) { return a < b ? a : b; }

int minVal(int mask, int node)
{
    if (mask == VISITED_ALL)
    {
        return adj[node][src];
    }

    if (dp[mask][node] != -1)
        return dp[mask][node];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i) == 0)
        {
            ans = min(ans, adj[node][i] + minVal((mask | (1 << i)), i));
        }
    }

    return dp[mask][node] = ans;
}

int main()
{
    int n;
    cin >> n;
    cin >> src;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int val;
            cin >> val;
            adj[i][j] = val;
        }
    }

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] = -1;
        }
    }
    // cout << minVal(src);
    return 0;
}