#include<iostream>
using namespace std;
const int n = 1e5 + 10;

int parent[n];
int ranking[n];

void make(int v)
{
    parent[v] = v;
    ranking[v] = 0;                                // Union by size
}

int find(int v)
{
    if(v==parent[v])
        return v;        
    return parent[v] = find(parent[v]);         // Path Compression or collapsing find
}

void Union(int a, int b)
{
    int root_1 = find(a);
    int root_2 = find(b);

    if (root_1 != root_2) {
        if (ranking[root_1] < ranking[root_2])
            swap(root_1, root_2);
        parent[root_2] = root_1;
        if (ranking[root_1] == ranking[root_2])
            ranking[root_1]++;
    }

}

int main()
{
    
    return 0;
}