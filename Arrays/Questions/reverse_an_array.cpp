#include<iostream>
using namespace std;

void print(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse(int arr[], int size)
{
    int mid = size/2;
    for(int i=0; i<mid; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    reverse(arr,5);
    int array[6] = {9,2,3,4,5,7};
    reverse(array,6);
    print(arr,5);
    print(array,6);
    return 0;
}