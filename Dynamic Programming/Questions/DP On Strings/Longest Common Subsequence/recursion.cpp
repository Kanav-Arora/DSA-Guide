#include <iostream>
using namespace std;

int solver(string s, string t, int ind1, int ind2)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (s[ind1] == t[ind2])
        return 1 + solver(s, t, ind1 - 1, ind2 - 1);
    else
        return 0 + max(solver(s, t, ind1 - 1, ind2), solver(s, t, ind1, ind2 - 1));
}

int lcs(string s, string t)
{
    return solver(s, t, s.length() - 1, t.length() - 1);
}

int main()
{

    return 0;
}