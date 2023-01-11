#include <iostream>
#include <vector>
using namespace std;

bool solver(string pattern, string text, int i, int j)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0)
        return false;
    if (j < 0)
    {
        for (int m = 0; m <= i; m++)
            if (pattern[m] != '*')
                return false;
        return true;
    }

    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return solver(pattern, text, i - 1, j - 1);
    }
    if (pattern[i] == '*')
        return solver(pattern, text, i, j - 1) || solver(pattern, text, i - 1, j);
    return false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length();
    int m = text.length();
    return solver(pattern, text, n - 1, m - 1);
}

int main()
{

    return 0;
}