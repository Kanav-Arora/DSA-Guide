/*
    Given an array nums of distinct integers return all possible
    permutations. You can return the answer in any order.
*/


#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > ans;

void permute(vector<int> &a, int idx)
{
    if(idx==a.size())
    {
        ans.push_back(a);
        return;
    }
    for(int i=idx; i<a.size(); i++)
    {
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx]);
    }

}
int main()
{
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i : a)
        cin>>i;
    permute(a,0);
    for(auto v: ans)
    {
        for(auto i : v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}