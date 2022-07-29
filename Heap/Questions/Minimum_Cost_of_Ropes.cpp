#include <iostream>
#include <queue>
using namespace std;

long long minCost(long long arr[], long long n)
{
    long long cost = 0;
    priority_queue<long long, vector<long long>, greater<long long>> minh;

    for (int i = 0; i < n; i++)
        minh.push(arr[i]);

    while (minh.size()>1)
    {
        long long first = minh.top();
        minh.pop();
        long long second = minh.top();
        minh.pop();

        long long rope = first + second;

        minh.push(rope);
        cost += (first + second);
    }

    return cost;
}

int main()
{
    long long arr[] = {4,3,2,6};
    cout<<minCost(arr,4);
    return 0;
}