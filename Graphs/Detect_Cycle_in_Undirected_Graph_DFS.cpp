#include<iostream>
#include<vector>
using namespace std;

bool DFS(vector<int> v[], int node, int parent, vector<bool> &visited)
{
    visited[node] = true;
    for(auto i: v[node])
    {
        if(!visited[i])
        {
            if(DFS(v,i,node,visited)==true)
                return true;
        }
        else if(i!=parent)
            return true;
    }

    return false;
}

int main()
{
    int vertices;
    cin>>vertices; 
    int edges;
    cin>>edges;
    vector<int> v[vertices+1];
    int v1,v2;
    while(edges--)
    {
        cin>>v1>>v2;\
        v[v1].push_back(v2);
    }

    cout<<endl<<"Graph Adjacency List created..."<<endl;

    for(int i=1; i<=vertices; i++)
    {
        cout<<"[ "<<i<<" ]";

        for(int j=0; j<v[i].size(); j++)
        {
            cout<<" -> "<<v[i][j];
        }

        cout<<endl;
    }

    vector<bool> visited(vertices+1,false);
    cout<<DFS(v,1,-1,visited)<<endl;
    return 0;
}


/*

7
14
1 2
1 3
2 1
2 5
3 1
3 4
3 6
4 3
5 2
5 7
6 3
6 7
7 5
7 6


7
12
1 2
1 3
2 1
2 5
3 1
3 4
3 6
4 3
5 2
5 7
6 3
7 5

*/