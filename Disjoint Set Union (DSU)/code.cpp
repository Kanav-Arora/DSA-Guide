#include<iostream>
using namespace std;
const int n = 1e5 + 10;

int parent[n];

void make(int v)
{
    parent[v] = v;
}

int find(int v)
{
    if(v==parent[v])
        return v;        
    return find(parent[v]);
}

void Union(int a, int b)
{
    int root_1 = find(a);
    int root_2 = find(b);

    if(root_1!=root_2)
    {
        parent[root_2] = root_1;
    }

}

int main()
{
    
    return 0;
}