#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int OptimalPatter(vector<int> v, int n)
{
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=0; i <n; i++)
    {
        q.push(v[i]);
    }

    int sum = 0;
    while(q.size()>1)
    {
        int v1  = q.top();
        q.pop();
        int v2 = q.top();
        q.pop();

        int temp = v1+v2;
        sum+=temp;
        q.push(temp);
    }

    return sum;
}

int main()
{
    int n;
    cin>>n;

    vector<int> v;

    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;

        v.push_back(val);
    }

    cout<<OptimalPatter(v,n);
    return 0;
}


/*

Input:

4
6 5 2 3

Output:

31

*/