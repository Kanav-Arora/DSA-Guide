#include <iostream>
#include <vector>
using namespace std;

int solver(string t, string s, int lt, int ls)
{
    if (ls < 0)
        return 1;
    if (lt < 0)
        return 0;

    if (t[lt] == s[ls])
        return solver(t, s, lt - 1, ls - 1) + solver(t, s, lt - 1, ls);
    else
        return solver(t, s, lt - 1, ls);
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    return solver(t, s, lt - 1, ls - 1);
}

int main()
{

    return 0;
}