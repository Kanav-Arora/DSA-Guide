#include <iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;

    if (lc < n && arr[largest] < arr[lc])
        largest = lc;

    if (rc < n && arr[largest] < arr[rc])
        largest = rc;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(a[i]);
    for (int i = 0; i < m; i++)
        ans.push_back(b[i]);
    int size = ans.size();

    for (int i = (size) / 2 - 1; i >= 0; i--)
        heapify(ans, size, i);

    return ans;
}

int main()
{

    return 0;
}