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

        void deletion()
        {
            arr[1] = arr[size];
            size--;
            int index = 1;
            while(index<size)
            {
                int lc = 2*index;
                int rc = 2*index+1;

                if(lc<size && arr[index]<arr[lc])
                {
                    swap(arr[index], arr[lc]);
                    index = lc;
                }

                else if(rc<size && arr[index]<arr[rc])
                {
                    swap(arr[index], arr[rc]);
                    index = rc;
                }
                else
                {
                    return;
                }
            }
        }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int lc = 2*i;
    int rc = 2*i+1;

    if(lc<n && arr[largest]<arr[lc])
        largest = lc;
    
    if(rc<n && arr[largest]<arr[rc])
        largest = rc;

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr, n, largest);
    }
}


int main()
{
    MaxHeap obj;
    obj.insert(50);
    obj.insert(55);
    obj.insert(53);
    obj.insert(52);
    obj.insert(54);

    obj.print();

    obj.deletion();
    obj.print();


    int arr[] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }
    for(int i=1; i<=n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}