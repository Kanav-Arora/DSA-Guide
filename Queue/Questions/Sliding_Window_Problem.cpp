#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> SlidingWindow(vector<int> v, int n, int k)
{
    deque<int> q;
    vector<int> res;

    for(int i=0; i<k; i++)
    {
        // pop from last till you get element greater than current element
        
        while(!q.empty() && v[i]>=v[q.back()])
            q.pop_back();
        
        q.push_back(i);
    }

    for(int i=k; i<n; i++)
    {
        res.push_back(v[q.front()]);

        while(!q.empty() && q.front()<=i-k)
            q.pop_front();

        while(!q.empty() && v[i]>=v[q.back()])
            q.pop_back();
        
        q.push_back(i);
    }

    res.push_back(v[q.front()]);


    return res;    
}

int main()
{
    vector<int> v = {4,1,3,5,1,2,3,2,1,1,5};
    vector<int> ans = SlidingWindow(v,11,3);

    for(auto a: ans)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}