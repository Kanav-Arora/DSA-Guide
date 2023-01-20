#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> res(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = res[i - 1];
        while (j > 0 && s[i] != s[j])
            j = res[j - 1];
        if (s[i] == s[j])
            j++;
        res[i] = j;
    }

    return res;
}

int KMP(string s, string t)
{
    vector<int> pref = prefix_function(t);
    int pos = -1;
    int i = 0, j = 0;

    while (i < s.length())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = pref[j - 1];
            else
                i++;
        }

        if (j == t.size())
        {
            pos = i - t.size();
        }
    }

    return pos;
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << KMP(s, t);
    return 0;
}