#include <iostream>
using namespace std;

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
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - 1-i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for (int ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}