#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> subArray(vector<int> arr, int k)
{
    unordered_map<int, int> map;

    int currsum = 0, start = -1, end = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        currsum += arr[i];
        if(currsum-k==0)
        {
            start = 0; end = i;
            break;
        }

        if (map.count(currsum - k) == 1)
        {
            start = map[currsum - k]+1;
            end = i;
            break;
        }

        map[currsum] = i;
    }

    if (start != -1)
    {
        vector<int> ans;
        for (int i = start; i <=end; i++)
        {
            ans.push_back(arr[i]);
        }

        return ans;
    }

    return {};
}

int main()
{
    vector<int> v = {10,15,-5,15,-10,5};

    vector<int> ans = subArray(v,5);
    if(ans.size()!=0)
    {
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"SubArray Not found"<<endl;
    }
    return 0;
}