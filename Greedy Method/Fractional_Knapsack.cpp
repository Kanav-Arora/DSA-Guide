#include <iostream>
#include <vector>
#include <queue>
using namespace std;

float MaxProfit(vector<int> profits, vector<int> weights, int n, int m)
{
    priority_queue<pair<float, int>> q;

    for (int i = 0; i < n; i++)
    {
        q.push({(float)profits[i] / weights[i], i});
    }

    float val = 0;
    int wt = 0;

    while (!q.empty() && wt < m)
    {
        pair<float, int> pair = q.top();
        q.pop();

        if (wt + weights[pair.second] <= m)
        {
            wt += weights[pair.second];
            val += profits[pair.second];
        }
        else
        {
            float req = m - wt;
            cout << req * (float(profits[pair.second] / weights[pair.second])) << endl;
            val += req * (float(profits[pair.second] / weights[pair.second]));
            wt = m;
        }
    }

    return val;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> profits, weights;

    for (int i = 0; i < n; i++)
    {
        int p, wt;
        cin >> p >> wt;

        profits.push_back(p);
        weights.push_back(wt);
    }

    cout << MaxProfit(profits, weights, n, m) << endl;
    return 0;
}

/*

7 15
10 2
5 3
15 5
7 7
6 1
18 4
3 1

*/