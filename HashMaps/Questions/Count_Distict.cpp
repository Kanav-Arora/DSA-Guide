#include<iostream>
#include<unordered_set>
using namespace std;

int CountDistinct(int arr[], int n)
{
    unordered_set<int> set;

    for(int i=0; i<n; i++)
        set.insert(arr[i]);

    return set.size();
}


int main()
{
    int arr[] = {5,6,2,1,5,5,1};
    cout<<CountDistinct(arr, 7);
    return 0;
}