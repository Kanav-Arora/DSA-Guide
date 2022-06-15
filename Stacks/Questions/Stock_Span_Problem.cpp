#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> StockSpan(int arr[], int n)
{
    stack<pair<int,int> > s;
    vector<int> v;

    for(int i=0; i<n; i++)
    {
        if(s.empty())
            v.push_back(1);
        
        else if(s.top().first>arr[i])
            v.push_back(1);
        
        else
        {
            if(s.empty())
                v.push_back(i);

            else
            {
                while(!s.empty() && s.top().first<=arr[i])
                {
                    s.pop();
                }
                if(s.empty())
                    v.push_back(i);
                else
                    v.push_back(i-s.top().second);   

            }
        }
        s.push({arr[i],i});
    }


    return v;
}

int main()
{
    int arr[] = {100,80,60,70, 60,75, 85};
    vector<int> v = StockSpan(arr,7);

    for(auto a: v)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}