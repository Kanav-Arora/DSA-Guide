#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// Approach:1

int kthLargest(vector<int> v, int k)
{
    vector<int> ans;
    int n = v.size();
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum+=v[j];

            ans.push_back(sum);
        }
    }

    sort(ans.begin(), ans.end(), greater<int>());

    return ans[k-1];
}

// Approach 2:

int KthLargest2(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> mh;
    int n = v.size();
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum+=v[j];

            if(mh.size()<k)
            {
                mh.push(sum);
            }
            else if(mh.top()<sum)
            {
                mh.pop();
                mh.push(sum);
            }
        }
    }
    
    return mh.top();
}

int main()
{
    cout<<kthLargest({3,-2,5},3);
    cout<<KthLargest2({3,-2,5},3);
    return 0;
}