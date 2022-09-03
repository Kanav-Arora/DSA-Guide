#include<iostream>
#include<vector>
using namespace std;

void SubSequences(vector<int> arr,int i, string temp, vector<string> &v)
{
    if(i==arr.size())
        return;
    
    SubSequences(arr,i+1,temp,v);

    temp+=to_string(arr[i]);
    v.push_back(temp);
    SubSequences(arr,i+1,temp,v);
}

int main()
{
    vector<string> v;
    vector<int> arr = {3,1,2};
    SubSequences(arr,0,"",v);

    for(auto i:v)
        cout<<i<<endl;
    return 0;
}