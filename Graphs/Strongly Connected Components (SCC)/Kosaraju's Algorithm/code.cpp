#include<stack>

void toposort(stack<int> &s, vector<int> adj[], int node, vector<bool> &vis)
{
    vis[node] = true;
    
    for(auto each :  adj[node])
    {
        if(!vis[each])
            toposort(s,adj,each, vis);
    }
    
    s.push(node);
}

void DFS(vector<int> adj[], int node, vector<bool> &vis)
{
    vis[node] = true;
    
    for(auto each :  adj[node])
    {
        if(!vis[each])
            DFS(adj,each, vis);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	stack<int> s;
    vector<int> adj[v];
    vector<int> revadj[v];
    vector<bool> vis(v,false);
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
            toposort(s,adj,i,vis);
    }
    
    for(int i=0; i<v; i++)
    {
        for(auto each: adj[i])
        {
            revadj[each].push_back(i);
        }
        vis[i] = false;
    }
        
    
    int count = 0;
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        
        if(vis[top])
            continue;
        
        count++;
        DFS(revadj,top,vis);
    }
    
    return count;
}