#include <iostream>
#include <climits>
using namespace std;

/*
    * Find minimum element of unsorted array and swap it with the element at begining
*/


void selectionSort(int arr[], int n)
{
    int min_ind = 0;
    //* for (int i = 0; i < n; i++)           -   i<n-1 because we don't need to check for last element
    for(int i=0; i<n-1; i++)
    {
        min_ind = i;
        //* for (int j = i; j < n; j++)       -   j=i+1 because no need to compare same elements
        for(int j=i+1; j<n; j++)
        {
            if(arr[min_ind]>arr[j])
                min_ind = j;
        }
        swap(arr[min_ind],arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    
    selectionSort(arr,n);

    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}