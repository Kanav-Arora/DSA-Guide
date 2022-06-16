#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> MAH(int arr[], int n)
{
    stack<pair<int,int> > s;
    vector<int> v1;

    for(int i=0; i<n; i++)
    {
        if(s.empty())
            v1.push_back(0);
        else if(s.top().first<arr[i])
        {
            v1.push_back(0);
        }
        else
        {
            while(!s.empty() && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                v1.push_back(i);
            }
            else
            {
                v1.push_back(i-s.top().second-1);
            }
        }
        s.push({arr[i],i});
    }

    vector<int> v2;

    while(s.empty()==0)
        s.pop();

    for(int i=n-1; i>-1; i--)
    {
        if(s.empty())
            v2.push_back(0);
        else if(s.top().first<arr[i])
        {
            v2.push_back(0);
        }
        else
        {
            while(!s.empty() && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                v2.push_back(n-1-i);
            }
            else
            {
                v2.push_back(s.top().second-i-1);
            }
        }
        s.push({arr[i],i});
    }
    
    reverse(v2.begin(), v2.end());
    vector<int> v;
    for(int i =0; i<v1.size(); i++)
        v.push_back((v1[i] + v2[i] + 1)*arr[i]);
    
    return v;
}

int main()
{
    int arr[] = {6,2,5,4,5,1,6};
    vector<int> v = MAH(arr, 7);

    for(auto a: v)
    {
        cout<<a<<" ";
    }

    cout<<endl;
    cout<<"MAH: "<<*max_element(v.begin(), v.end());
    return 0;
}