#include<iostream>
#include<unordered_set>
using namespace std;

int Intersection_Two_Arrays(int arr1[], int n, int arr2[], int m)
{
    unordered_set<int> set;

    for(int i=0; i<n; i++)
        set.insert(arr1[i]);

    for(int i=0; i<m; i++)
        set.insert(arr2[i]);
    
    return n+m-set.size();
}

int main()
{
    int arr1[] = {3,2,1,4,5};
    int arr2[] = {3,5,9,0};

    cout<<Intersection_Two_Arrays(arr1,5,arr2,4);
    return 0;
}