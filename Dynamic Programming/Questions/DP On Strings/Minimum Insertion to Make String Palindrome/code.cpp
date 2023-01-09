#include <iostream>
#include <vector>
using namespace std;

int minInsertion(string &s)
{
    string t = s;
    reverse(t.begin(), t.end());

    vector<int> prev(t.length() + 1, 0), curr(t.length() + 1, 0);

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = 0 + max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return s.length() - prev[t.length()];
}

int main()
{

    return 0;
}