#include <iostream>
#include <vector>
using namespace std;

int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<double> arr(m + 1, 0);
    arr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                arr[j] = (arr[j - 1] + arr[j]);
            }
        }
    }

    return (int)arr[m];
}

int main()
{

    return 0;
}