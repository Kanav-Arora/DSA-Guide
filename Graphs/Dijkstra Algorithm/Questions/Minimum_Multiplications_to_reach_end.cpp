#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef pair<int,int> pr;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    queue<pr> q;
    q.push({start, 0});

    vector<int> dist(100000, 1e9);
    dist[start] = 0;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        int val = front.first;
        int no = front.second;

        for (auto i : arr)
        {
            int num = val * i % 100000;
            if (no + 1 < dist[num])
            {
                if (num == end)
                    return no + 1;
                dist[num] = no + 1;
                q.push({num, no + 1});
            }
        }
    }

    return -1;
}

int main()
{

    return 0;
}