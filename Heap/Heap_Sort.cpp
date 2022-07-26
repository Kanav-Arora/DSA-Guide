#include<iostream>
using namespace std;


class MaxHeap
{
    int arr[100];
    int size;

    public:
        MaxHeap()
        {
            arr[0] = -1;
            size= 0;
        }

        void insert(int val)
        {
            size++;
            int index = size;
            arr[index] = val;

            while(index>1)
            {
                int parent = index/2;

                if(arr[parent]<arr[index])
                {
                    swap(arr[index], arr[parent]);
                    index = parent;
                }

                else
                {
                    return;
                }
            }
        }

        void print()
        {
            for(int i=1; i<=size; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int lc = 2*i;
    int rc = 2*i+1;

    if(lc<=n && arr[largest]<arr[lc])
        largest = lc;
    
    if(rc<=n && arr[largest]<arr[rc])
        largest = rc;

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int size)
{
    int t = size;

    while(t>1)
    {
        swap(arr[t], arr[1]);
        t--;

        heapify(arr,t, 1);
    }
}


int main()
{
    int arr[] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i=n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }
    for(int i=1; i<=n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    heapSort(arr,n);
    for(int i=1; i<=n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}