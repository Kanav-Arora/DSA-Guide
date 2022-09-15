// GFG: Alien Dictionary

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];

    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int ptr1 = 0, ptr2 = 0;

        while (ptr1 != s1.length() && ptr2 != s2.length())
        {
            if (s1[ptr1] != s2[ptr2])
            {
                adj[s1[ptr1] - 'a'].push_back(s2[ptr2] - 'a');
                break;
            }
            ptr1++;
            ptr2++;
        }
    }

    int indegree[K] = {0};

    for (int i = 0; i < K; i++)
    {
        for (auto k : adj[i])
        {
            indegree[k]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < K; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    string ans = "";
    while (!q.empty())
    {
        int front = q.front();
        ans += (front + 'a');
        q.pop();

        for (auto i : adj[front])
        {
            indegree[i]--;

            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}