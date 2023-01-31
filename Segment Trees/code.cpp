#include <iostream>
#include <vector>
using namespace std;

int arr[100005], seg[4 * 100005], n;

void build(int node, int l, int h)
{
    if (l == h)
    {
        seg[node] = arr[l];
        return;
    }

    int mid = l + (h - l) / 2;
    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, h);
    seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
}

int query(int node, int low, int high, int l, int r)
{
    if (l <= low && high <= r) // if query is greater than the call range
        return seg[node];

    if (l > high || r < low) // if query does not lie in current call range
        return INT_MIN;

    int mid = low + (high - low) / 2;
    int lt = query(2 * node + 1, low, mid, l, r);      // query on left subhalf
    int rt = query(2 * node + 2, mid + 1, high, l, r); // query on right subhalf
    return max(lt, rt);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << endl;
    }
    return 0;
}

/*

8
5 4 3 2 1 8 6 10
2
2 5
4 7

*/