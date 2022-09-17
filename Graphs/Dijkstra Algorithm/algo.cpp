#include<iostream>
#include <list>
#include <set>
#include <unordered_map>
#include<climits>
#include <list>
#include <vector>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> mp;

    for (int i = 0; i < vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        mp[u].push_back({v, wt});
        mp[v].push_back({u, wt});
    }

    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> st;

    dist[source] = 0;

    st.insert({0, source});

    while (!st.empty())
    {
        pair<int, int> p = *(st.begin());
        st.erase(st.begin());
        int distance = p.first;
        int node = p.second;

        for (auto k : mp[node])
        {
            int visit = k.first;
            int wt = k.second;

            if (distance + wt < dist[visit])
            {
                auto record = st.find({dist[visit], visit});
                if (record != st.end())
                    st.erase(record);
                dist[visit] = distance + wt;

                st.insert({dist[visit], visit});
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}