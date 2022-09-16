#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

void topoSort(int i, vector<pair<int,int>> adj[], vector<bool> &vis, stack<int> &stk)
{
    vis[i] = true;

    for(auto k: adj[i])
    {
        int u = k.first;
        if(!vis[u])
            topoSort(u,adj,vis,stk);
    }
    stk.push(i);
}

vector<int> ShortestPathinDAG(int src, int N, int M, vector<int> edges[])
{
    vector<pair<int,int>> adj[N];

    for(int i=0; i<M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt});
    }

    vector<bool> vis(N,false);
    stack<int> stk;
    for(int i=0; i<N; i++)
    {
        if(!vis[i])
        {
            topoSort(i,adj, vis, stk);
        }
    }

    // Make distance vector and initialize it with infinite values

    vector<int> dist(N,INT_MAX);

    dist[src] = 0;

    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();

        for(auto i: adj[top])
        {
            int v = i.first;
            int wt = i.second;

            if(dist[top]+wt<dist[v])
                dist[v] = dist[top] + wt;
        }
    }

    return dist;
}

int main()
{
    int n = 6;
    int m = 9;

    vector<int> edges[m];
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(wt);
    }

    vector<int> ans = ShortestPathinDAG(0,n,m,edges);

    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}


/*

0 1 5
0 2 3
1 2 2
1 3 6
2 5 2
2 3 7
2 4 4
3 4 -1
4 5 -2

*/