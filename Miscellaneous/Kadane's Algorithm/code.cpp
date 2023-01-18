#include <iostream>
#include <vector>
using namespace std;

int solver(vector<int> arr)
{
    int n = arr.size();
    int sum = 0, maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int main()
{
    vector<int> v({5, 4, -1, 7, 8});
    cout << solver(v) << endl; // 23
    return 0;
}