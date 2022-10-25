#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

static bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first <= p2.first;
}

int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({arr[i], dep[i]});
    }

    sort(v.begin(), v.end(), comp);

    priority_queue<int, vector<int>, greater<int>> q;

    int plat = 0;

    for (int i = 0; i < n; i++)
    {
        if (q.empty())
        {
            q.push(v[i].second);
        }
        else
        {
            if (v[i].first <= q.top())
            {
                q.push(v[i].second);
            }
            else
            {
                q.pop();
                q.push(v[i].second);
            }
        }

        if (q.size() > plat)
            plat = q.size();
    }

    return plat;
}

int main()
{

    return 0;
}