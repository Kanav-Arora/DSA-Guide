#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NearestSmallerLeft(int arr[], int n)
{
    stack<int> s;
    vector<int> v;

    for(int i=0; i<n; i++)
    {
        if(s.empty())
            v.push_back(-1);

        else if(s.top()<arr[i])
            v.push_back(s.top());

        else
        {
            while(!s.empty() && s.top()>=arr[i])
                s.pop();
            
            if(s.empty())
                v.push_back(-1);
            
            else if(s.top()<arr[i])
                v.push_back(s.top());
        }

        s.push(arr[i]);
    }

    return v;
}

int main()
{
    int arr[]= {4,5,2,10,8};
    vector<int> v = NearestSmallerLeft(arr,5);

    for(auto a:v)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}