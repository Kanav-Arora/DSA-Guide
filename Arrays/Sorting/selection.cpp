#include <iostream>
#include <climits>
using namespace std;

/*
    * Find minimum element of unsorted array and swap it with the element at begining
*/

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

    //* for (int j = 0; j < n-1; j++)           -   j<n-1 because we don't need to check for last element
    for (int j = 0; j < n-1; j++)
    {
        int mini = INT_MAX;
        int ind = 0;
        //* for (int i = j; i < n; i++)       -   i=j+1 because no need to compare same elements
        for (int i = j+1; i < n; i++)
        {
            if (arr[i] < arr[j])
            {
                int swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }

    for (int ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}