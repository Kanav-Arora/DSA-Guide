#include<iostream>
#include<stack>
#include <algorithm>
#include<vector>
using namespace std;


vector<int> NearestGreaterRight(int arr[], int n)
{
    stack<int> s;
    vector<int> res;
    for(int i=n-1; i>-1; i--)
    {
        if(s.empty()==1)
        {
            res.push_back(-1);
            s.push(arr[i]);
        }
        else
        {   
            if(s.top()>arr[i])
            {
                res.push_back(s.top());
                s.push(arr[i]);
                continue;
            }

            else
            {
                while(s.top()<=arr[i])
                    s.pop();
                
                if(s.empty()==1)
                {
                    res.push_back(-1);
                    s.push(arr[i]);
                }

                else if(s.top()>arr[i])
                {
                    res.push_back(s.top());
                    s.push(arr[i]);
                    continue;
                }
            }
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    int arr[] = {1,3,2,4};
    vector<int> v;
    v = NearestGreaterRight(arr,4);

    for(auto a : v)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}