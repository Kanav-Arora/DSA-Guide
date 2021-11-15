/*
    Count the inversions in the given array
    Two elements a[i] and a[j] form an inversion if a[i]>a[j] and i<j


*/


#include<iostream>
using namespace std;

long long merge(int arr[], int l, int mid, int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int inv=0;
    int a1[n1];
    int a2[n2];
    for(int i=0; i<n1; i++)
    {
        a1[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++)
    {
        a2[i] = arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 and j<n2)
    {
        if(a1[i]<a2[j])
        {
            arr[k] = a1[i];
            i++,k++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
            k++;
            inv+=n1-i;
        }
    }
    while(i<n1)
    {
        arr[k] = a1[i];
        k++,i++;
    }
    while(j<n2)
    {
        arr[k] = a2[j];
        j++,k++;
    }
    return inv;
}

long long mergesort(int arr[], int l, int r)
{
    int inv = 0;
    if(l<r)
    {
        int mid = (l+r)/2;
        inv+= mergesort(arr,l,mid);
        inv+= mergesort(arr,mid+1,r);
        inv+= merge(arr,l,mid,r);
    }
    return inv;
}

int main()
{
    int arr[] = {3,2,1};
    int inv = mergesort(arr,0,2);
    for(int i=0; i<3; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<inv<<endl;
    return 0;
}