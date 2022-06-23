#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> firstNegative(vector<int> v, int n, int k)
{
    queue<int> q;
    vector<int> ans;

    for(int i=0; i<k; i++)
    {
        if(v[i]<0)
            q.push(i);
    }

    for(int i=k; i<n; i++)
    {
        if(q.empty())
            ans.push_back(0);
        else
            ans.push_back(v[q.front()]);

        while(!q.empty() && q.front()<=i-k)
        {
            q.pop();
        }

        if(v[i]<0)
            q.push(i);

    }

    if(q.empty())
            ans.push_back(0);
        else
            ans.push_back(v[q.front()]);


    return ans;
}

int main()
{
    vector<int> v = {-8,2,3,-6,10};
    vector<int> ans = firstNegative(v,5,2);

    for(auto a : ans)
        cout<<a<<" ";
    
    cout<<endl;

    return 0;
}