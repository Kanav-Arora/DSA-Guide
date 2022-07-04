
// Remove duplicates from sorted array




# include<iostream>
using namespace std;
void remove(int arr[] , int n)
{
    int temp[n];
    temp[0]=arr[0];
    int res=1;

    for(int i=1;i<n;i++)
    {
        if(temp[res-1]!=arr[i])
        {
            temp[res]=arr[i];
            res++;
        }
    }

    for(int i=0;i<res;i++)
    {
        arr[i]=temp[i];
    }
    
    cout<<"Size of array after remove duplicate : "<<res<<endl;

    cout<<"Array after remove duplicate : ";
    for(int i=0;i<res;i++)
    {
        cout<<arr[i]<<" ";

    }
}

int main()
{
    int arr[5]={1,2,2,3,3};
    int n=5;

    remove(arr,n);
}












// Efficient approach

/*

# include<iostream>
using namespace std;
void remove(int arr[] , int n)
{
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[res-1])
        {
            arr[res]=arr[i];
            res++;
        }
    }

    cout<<"Size of array after remove duplicates : "<< res<<endl;

    cout<<"\nArray after remove duplicates : ";
    for(int i=0;i<res;i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main()
{
    int arr[5]={10,20,20,30,30};
    int n=5;

    remove(arr,n);

}


*/










