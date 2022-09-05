#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<int> vertices[], int target, vector<bool> &visited, vector<int> &order)
{
    visited[target] = 1;
    order.push_back(target);
    for(auto i : vertices[target])
    {
        if(visited[i]==0)
        {
            DFS(vertices,i,visited, order); 
        }
    }
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
        cin>>v1>>v2;
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

    cout<<endl;


    vector<int> order;
    vector<bool> visited(vertices+1, false);
    DFS(v,1,visited, order);

    for(int i : order)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

/*

8
16
1 2
1 3
2 1
2 5
2 6
3 1
3 4
3 7
4 3
4 8
5 2
6 2
7 3
7 8
8 4
8 7

*/