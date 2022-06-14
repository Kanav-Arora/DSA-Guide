#include<iostream>
#include<stack>
#include <algorithm>
#include<vector>
using namespace std;

void display(vector<int> v)
{
    for(auto a:v)
    {
        cout<<a<<" ";
    }
    cout<<endl;
}

vector<int> NearestGreaterLeft(int arr[], int n)
{
    stack<int> s;
    vector<int> res;

    for(int i=0; i<n; i++)
    {
        if(s.empty()==1)
        {
            res.push_back(-1);

            display(res);
        }

        else if(!s.empty() && s.top()>arr[i])
        {
            res.push_back(s.top());

            display(res);
        } 

        else if(!s.empty() && s.top()<=arr[i])
        {
                while(s.top()<=arr[i] && !s.empty())
                    s.pop();
                
                if(s.empty()==1)
                {
                    res.push_back(-1);

                    display(res);
                }

                else if(s.top()>arr[i])
                {
                    res.push_back(s.top());
                    display(res);
                }   
        }
        s.push(arr[i]);
    }

    return res;
}

int main()
{
    int arr[] = {1,3,2,4};
    vector<int> v;
    v = NearestGreaterLeft(arr,4);

    for(auto a : v)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}