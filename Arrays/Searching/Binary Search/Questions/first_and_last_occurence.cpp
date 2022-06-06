#include<iostream>
using namespace std;

pair<int,int> firstLastOccurence(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start<end)
    {
        mid = start + (end-start)/2;
        if(arr[mid]<target)     start = mid+1;
        else    end = mid;
    }

    int first = start;

    start = 0;
    end = n-1;
    mid = start + (end-start)/2;

    while(start<end)
    {
        mid = start + (end-start)/2;
        if(arr[mid]<=target)     start = mid;
        else    end = mid-1;
    }

    int last = start;

    return {first,last};
}


int main()
{
    int arr[] = {1,4,5,6,10,10,10,12,14};
    pair<int,int> p = firstLastOccurence(arr, 9, 10);

    cout<<p.first<<" "<<p.second<<endl;

    return 0;
}