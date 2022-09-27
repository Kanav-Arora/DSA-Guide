#include<algorithm>

bool comp(vector<int> &v1, vector<int> &v2)
{
    return v1[2]<v2[2];
}

void makeSet(vector<int> &parent, vector<int> &rank)
{
    for(int i=0; i<parent.size(); i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>& parent, int u)
{
    if(parent[u]==u)
        return u;
    
    return parent[u] = findParent(parent, parent[u]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent,u);
    v = findParent(parent,v);
    
    if(rank[u]<rank[v])
        swap(u,v);
    
    parent[v] = u;
    
    if(rank[v]==rank[u])
        rank[u]++;
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), comp);  
    
    vector<int> parent(n);
    vector<int> rank(n);
    
    makeSet(parent,rank);
    
    int sum = 0;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        
        int p1 = findParent(parent,u);
        int p2 = findParent(parent,v);
        
        if(p1==p2)
            continue;
        else
        {
            sum+=wt;
            unionSet(u,v,parent,rank);
        }
    }
    
    return sum;
}