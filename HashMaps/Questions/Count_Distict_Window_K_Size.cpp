#include<iostream>
#include<map>
using namespace std;

void Count_Distict(int arr[], int n, int k)
{
    map<int,int> mapping;

    int i;
    for(i=0; i<k; i++)
        mapping[arr[i]]++;

    cout<<mapping.size()<<" ";
    
    for(i=k; i<n; i++)
    {
        mapping[arr[i]]++;
        if(mapping[arr[i-k]]==1)
            mapping.erase(arr[i-k]);
        else
            mapping[arr[i-k]]--;

        cout<<mapping.size()<<" ";
    }
}


int main()
{
    int arr[] = {1,2,2,1,3,1,1,3};
    Count_Distict(arr,8,4);
    return 0;
}