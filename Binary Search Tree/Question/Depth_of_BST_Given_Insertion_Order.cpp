#include<iostream>
#include<map>
using namespace std;


int DepthOfOrder(int arr[], int n)
{
    map<int, int> mapping;
    mapping[arr[0]] = 1;
    int ans = 1;
    int i=1;

    while(i<n)
    {
        int curr = arr[i++];
        auto prev = mapping.upper_bound(curr);
        auto next = mapping.lower_bound(curr);
        int leftdepth = prev==mapping.cbegin() ? 0 : prev->second;
        int rightdepth = next==mapping.cend() ? 0 : next->second;
        int depth = max(leftdepth, rightdepth)+1;
        ans = max(ans, depth);
        mapping[curr] = depth;
    }

    return ans;
}


int main()
{
    int arr[] = {2,1,3,4};
    cout<<DepthOfOrder(arr,4);
    return 0;
}