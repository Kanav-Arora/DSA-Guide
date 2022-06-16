#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int MAH(vector<int> arr, int n)
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
    
    return *max_element(v.begin(), v.end());
}

int MaxAreaRectangle(vector<vector<int> > v, int rows, int cols)
{
    vector<int> res;
    vector<int> input;

    for(int i=0; i<cols; i++)
        input.push_back(0);

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            input[i]+=v[i][j];
            
        res.push_back(MAH(input, cols));
    }

    return *max_element(res.begin(), res.end());
}

int main()
{
    vector<vector<int> > v = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    cout<<MaxAreaRectangle(v,4,4)<<endl;
    return 0;
}