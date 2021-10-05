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
    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n - 1-j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int swap = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = swap;
            }
        }
    }
    for (int ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}