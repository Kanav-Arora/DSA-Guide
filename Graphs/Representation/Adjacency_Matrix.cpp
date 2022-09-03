#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
    {
        int vi,vj;
        cin>>vi>>vj;
        arr[vi][vj] = 1;
    }
    return 0;
}