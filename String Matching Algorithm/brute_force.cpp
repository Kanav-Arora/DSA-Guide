#include <iostream>
#include <vector>
using namespace std;

int match(string s, string t)
{
    int i = 0, last = i, j = 0;

    while (i < s.length())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = last + 1;
            last++;
            j = 0;
        }

        if (j == t.length())
            return i - t.length();
    }

    return -1;
}

int main()
{
    string s = "abadcm";
    string t = "n";
    cout << match(s, t) << endl;
    return 0;
}