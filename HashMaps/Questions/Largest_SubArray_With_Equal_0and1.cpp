#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> subArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]==0)
            arr[i] = -1;
    }


    unordered_map<int, int> map;

    int currsum = 0, start = -1, end = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        currsum += arr[i];
        if(currsum==0)
        {
            start = 0; end = i;
            break;
        }

        if (map.count(currsum) == 1)
        {
            if((i-map[currsum]+1 > end-start) || start == -1)
            {
                start = map[currsum]+1;
                end = i;   
            } 
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
    vector<int> v = {1,1,0,1,1,0,0};

    vector<int> ans = subArray(v);
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