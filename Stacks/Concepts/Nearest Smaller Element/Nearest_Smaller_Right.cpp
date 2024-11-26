#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> NearestSmallerRight(int arr[], int n)
{
    vector<int> v;
    stack<int> s;

    for(int i=n-1; i>-1; i--)
    {
        if(s.empty())
            v.push_back(-1);
        
        else if(s.top()<arr[i])
            v.push_back(s.top());
        
        else
        {
            while(!s.empty() &&  s.top()>=arr[i])
                s.pop();
            
            if(s.empty())
                v.push_back(-1);
            
            else if(s.top()<arr[i])
                v.push_back(s.top());
        }
        s.push(arr[i]);
    }

    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    int arr[]= {4,5,2,10,8};
    vector<int> v = NearestSmallerRight(arr,5);

    for(auto a:v)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}