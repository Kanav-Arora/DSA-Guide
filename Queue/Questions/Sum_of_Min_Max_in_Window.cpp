#include<iostream>
#include<deque>
#include<vector>
using namespace std;


vector<int> Sum_Min_Max(vector<int> v, int k)
{
    deque<int> maxi;
    deque<int> mini;

    int n = v.size();

    vector<int> ans;

    for(int i=0; i<k; i++)
    {
        if(maxi.empty() && mini.empty())
        {
            maxi.push_back(i);
            mini.push_back(i);
        }

        while(!maxi.empty() && v[i]>=v[maxi.back()])
            maxi.pop_back();
        
        maxi.push_back(i);

        while(!mini.empty() && v[i]<=v[mini.back()])
            mini.pop_back();
        
        mini.push_back(i);
    }

    for(int i=k; i<n; i++)
    {
        ans.push_back(v[maxi.front()] + v[mini.front()]);

        while(!maxi.empty() && maxi.front()<=i-k)
        {
            maxi.pop_front();
        }

        while(!mini.empty() && mini.front()<=i-k)
        {
            mini.pop_front();
        }

        while(!maxi.empty() && v[i]>=v[maxi.back()])
            maxi.pop_back();
        
        maxi.push_back(i);

        while(!mini.empty() && v[i]<=v[mini.back()])
            mini.pop_back();
        
        mini.push_back(i);

    }

    ans.push_back(v[maxi.front()] + v[mini.front()]);

    return ans;
}

int main()
{
    vector<int> v = {2,5,-1,7,-3, -1, -2};
    vector<int> ans = Sum_Min_Max(v,4);

    for(auto a:ans)
    {
        cout<<a<<" ";
    }

    cout<<endl;
    return 0;
}