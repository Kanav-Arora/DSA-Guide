#include<iostream>
#include<unordered_set>
using namespace std;

int Union_Two_Arrays(int arr1[], int n, int arr2[], int m)
{
    unordered_set<int> set;

    for(int i=0; i<n; i++)
        set.insert(arr1[i]);

    for(int i=0; i<m; i++)
        set.insert(arr2[i]);
    
    return set.size();
}

int main()
{
    
    return 0;
}