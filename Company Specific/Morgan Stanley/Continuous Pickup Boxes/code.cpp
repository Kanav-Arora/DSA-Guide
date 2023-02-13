#include <iostream>
#include <vector>
using namespace std;

/*
    A factory has several boxes aligned in a row. You have a machine to pick up a subset of boxes. You are provided with N queries,
    where each query contains a range of boxes that need pickup. You need to determine the maximum number of continuous pickups the
    machine will have to make in the pickup process.
*/

inline int max(int a, int b) { return a > b ? a : b; }

int main()
{
    int q;
    cin >> q;
    vector<pair<int, int>> v;

    for (int i = 0; i < q; i++)
    {
        int s, e;
        cin >> s >> e;
        v.push_back(make_pair(s, e));
    }

    sort(v.begin(), v.end());
    vector<pair<int, int>> m_vec;
    m_vec.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        auto curr = v[i];

        if ((curr.first - 1) <= m_vec.back().second)
        {
            auto p = m_vec.back();
            m_vec.pop_back();
            m_vec.push_back(make_pair(p.first, curr.second));
        }
        else
            m_vec.push_back(curr);
    }

    int maxi = 0;
    for (int i = 0; i < m_vec.size(); i++)
    {
        auto val = m_vec[i];
        cout << val.first << " " << val.second << endl;
        maxi = max(maxi, val.second - val.first + 1);
    }
    cout << maxi << endl;
    return 0;
}
/*

3
1 5
6 9
11 17

*/