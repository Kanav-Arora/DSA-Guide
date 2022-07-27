#include<iostream>
using namespace std;

class MinHeap
{
    int arr[100];
    int size;

    public:
        MinHeap()
        {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val)
        {
            size++;
            int index = size;
            arr[size] = val;

            while(index>1)
            {
                if(arr[index]<arr[index/2])
                {
                    swap(arr[index],arr[index/2]);
                    index = index/2;
                }

                else
                    return;
            }
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

                if(lc<=size && arr[index]>arr[lc])
                {
                    swap(arr[lc],arr[index]);
                    index = lc;
                }

                else if(rc<=size && arr[index]>arr[rc])
                {
                    swap(arr[rc],arr[index]);
                    index = rc;
                }

                else
                    return;
            }
        }

        void print()
        {
            for(int i=1; i<=size; i++)
                cout<<arr[i]<<" ";
            
            cout<<endl;
        }
};

void heapify(int arr[], int size, int i)
{
    int smallest = i;
    int lc = 2*i;
    int rc = 2*i+1;

    if(lc<=size && arr[smallest]>arr[lc])
        smallest = lc;
    
    if(rc<=size && arr[smallest]>arr[rc])
        smallest = rc;
    
    if(smallest!=i)
    {
        swap(arr[i], arr[smallest]);

        heapify(arr,size,smallest);
    }
}

void buildHeap(int arr[], int size)
{
    for(int i=size/2; i>0; i--)
        heapify(arr,size, i);
}

void heapSort(int arr[], int size)
{
    buildHeap(arr,size);

    int index = size;

    while(index>1)
    {
        swap(arr[index],arr[1]);
        index--;
        buildHeap(arr,index);
    }
}

int main()
{
    MinHeap hp;

    hp.insert(8);
    hp.insert(5);
    hp.insert(6);
    hp.insert(3);
    hp.insert(2);

    hp.print();

    hp.deletion();

    hp.print();

    int arr[] = {-1,8,5,6,3,2};
    int size = 5;

    buildHeap(arr,size);

    for(int i=1; i<=size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    heapSort(arr,size);
    for(int i=1; i<=size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}