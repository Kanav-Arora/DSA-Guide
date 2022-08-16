#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> FourSum(vector<int> arr, int target)
{
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    set<vector<int>> s;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int newt = target - arr[i] - arr[j];

            int ptr1 = j+1;
            int ptr2 = n-1;

            while(ptr1<ptr2)
            {
                if(arr[ptr1]+arr[ptr2]==newt)
                {
                    s.insert({arr[i],arr[j],arr[ptr1],arr[ptr2]});
                    ptr1++; ptr2--;
                }
                else if(arr[ptr1]+arr[ptr2]>newt)
                    ptr2--;
                else
                    ptr1++;
            }
        }
    }

    for(auto i : s)
        ans.push_back(i);

    return ans;
}

int main()
{
    
    return 0;
}