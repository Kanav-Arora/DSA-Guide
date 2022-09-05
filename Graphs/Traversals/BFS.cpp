#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFS(vector<int> adjL[], int start, int vertices)
{
        queue<int> q;
        q.push(start);
        vector<int> visited(vertices,0);
        visited[start] = 1;
        vector<int> order;
        while(!q.empty())
        {
                int front = q.front();
                q.pop();
                order.push_back(front);
                for(auto i:adjL[front])
                {
                    if(visited[i]==0)
                    {
                        visited[i]=1;
                        q.push(i);
                    }
                }
        }

        return order;
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

    vector<int> order = BFS(v,6, vertices);

    for(int i : order)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}


/*

9
18
1 2
1 6
2 1
2 3
2 4
3 2
4 2
4 5
5 4
5 8
6 1
6 7
6 9
7 6
7 8
8 5
8 7
9 6

*/