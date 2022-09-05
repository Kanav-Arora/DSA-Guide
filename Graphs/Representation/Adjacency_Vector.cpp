#include<iostream>
#include<vector>
using namespace std;



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
    return 0;
}