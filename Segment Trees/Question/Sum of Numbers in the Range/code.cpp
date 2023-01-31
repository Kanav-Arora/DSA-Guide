#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
public:
    int n;
    vector<int> seg;
    vector<int> arr;
    void build(int node, int l, int h)
    {
        if (l == h)
        {
            seg[node] = arr[l];
            return;
        }

        int mid = (l + h) >> 1;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, h);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    NumArray(vector<int> &nums)
    {
        n = nums.size();
        seg = vector<int>(4 * n, 0);
        arr = nums;
        build(0, 0, n - 1);
    }

    void helper(int node, int ind, int val, int l, int h)
    {
        if (l == h && l == ind)
        {
            seg[node] = val;
            return;
        }

        int mid = (l + h) >> 1;
        if (ind >= l && ind <= mid)
            helper(2 * node + 1, ind, val, l, mid);
        else
            helper(2 * node + 2, ind, val, mid + 1, h);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void update(int index, int val)
    {
        arr[index] = val;
        helper(0, index, val, 0, n - 1);
    }

    int query(int node, int low, int high, int l, int r)
    {
        if (l <= low && high <= r)
            return seg[node];

        if (l > high || r < low)
            return 1e9;

        int mid = low + (high - low) / 2;
        int lt = query(2 * node + 1, low, mid, l, r);
        int rt = query(2 * node + 2, mid + 1, high, l, r);

        if (lt == 1e9)
            return rt;
        if (rt == 1e9)
            return lt;
        return lt + rt;
    }

    int sumRange(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
};

int main()
{

    return 0;
}