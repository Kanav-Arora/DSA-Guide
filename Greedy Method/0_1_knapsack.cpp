#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int MaxProfit(vector<int> profits, vector<int> weights,int n, int m)
{
    priority_queue<pair<float,int>> q;

    for(int i=0; i<n; i++)
    {
        q.push({(float)profits[i]/weights[i],i});
    }

    int val = 0, wt =0;

    while(!q.empty() && wt<m)
    {
        pair<float,int> pair = q.top();
        q.pop();

        if(wt+ weights[pair.second] <=m)
        {
            wt+=weights[pair.second];
            val+=profits[pair.second];
        }
    }

    return val;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> profits,weights;

    for(int i=0; i<n; i++)
    {
        int p,wt;
        cin>>p>>wt;

        profits.push_back(p);
        weights.push_back(wt);
    }

    cout<<MaxProfit(profits,weights,n,m)<<endl;
    return 0;
}