#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// Approach 1: Sort Vector
// return (k-1)th index


// Approach 2:   O(k lg(n))

void heapify(vector<int> &arr, int size, int i)
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
        swap(arr[smallest],arr[i]);

        heapify(arr,size, smallest);
    }
}

void buildHeap(vector<int> &arr, int size)
{
    for(int i=size/2; i>0; i--)
    {
        heapify(arr,size,i);
    }
}

int KthSmallest(vector<int> &arr, int size, int k)
{
    int i = k-1;
    buildHeap(arr,size);

    for(int i=1; i<=size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    while(i--)
    {
        arr[1] = arr[size];
        size--;
        heapify(arr,size,1);
    }

    return arr[1];
}


// Approach 3:

int KthSmallest2(vector<int> arr, int size, int k)
{
    priority_queue<int> heap;

    for(int i=1; i<=k; i++)
        heap.push(arr[i]);

    for(int i=k+1; i<=size; i++)
    {
        int ele = arr[i];

        if(ele<heap.top())
        {
            heap.pop();
            heap.push(ele);
        }
    }

    return heap.top();
}

int main()
{
    vector<int> arr = {-1,2,8,6,4,1};

    cout<<KthSmallest2(arr,5,2);
    return 0;
}