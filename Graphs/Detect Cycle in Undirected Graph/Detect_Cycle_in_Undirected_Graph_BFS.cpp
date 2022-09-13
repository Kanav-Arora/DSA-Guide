#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool CycleDetection(vector<int> v[], int vertices)
{
    vector<int> visited(vertices+1,false);

    visited[1] = true;
    queue<pair<int,int>> q;         // curr, parent
    q.push({1,-1});

    while(!q.empty())
    {
        int curr = q.front().first;
        int parent = q.front().second;
        visited[curr] = 1;
        q.pop();
        for(auto i:v[curr])
        {
            if(!visited[i])
                q.push({i,curr});

            else if(i!=parent)
                return true;
        }
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

    cout<<CycleDetection(v,vertices);
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