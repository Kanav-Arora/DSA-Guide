#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool toCompare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first<p2.first;
}

int main()
{
    vector< pair<int,int> > v1;
    int arr[] = {10,3,5,2,6,7};
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        v1.push_back(make_pair(arr[i],i));
    }
    sort(v1.begin(), v1.end(), toCompare);

    cout<<"Order of indexes:"<<endl;
    for(int i=0; i<v1.size(); i++)
    {
        cout<<v1[i].second<<" ";
    }
    cout<<endl;
    return 0;
}