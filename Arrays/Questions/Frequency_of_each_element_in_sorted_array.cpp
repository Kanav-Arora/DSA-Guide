// Frequency of each element in sorted array


# include<iostream>
using namespace std;
void freq(int arr[] , int n)
{
    int freqq=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        freqq++;

        else
        {
            cout<<"FR of "<<arr[i-1]<<" is = "<<freqq<<endl;
            freqq=1;

        }
    }
    cout<<"FR of "<<arr[n-1]<<" is : "<<freqq<<endl;
}


int main()
{
    int arr[5]={2,2,5,7,7};
    int n=5;

    freq(arr,n);


}