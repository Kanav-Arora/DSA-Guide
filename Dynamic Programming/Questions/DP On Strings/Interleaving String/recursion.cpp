#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool solver(string s1, string s2, string s3, int i, int j, int k)
    {
        if (k == s3.length() && i == s1.length() && j == s2.length())
            return true;

        bool c1 = false, c2 = false;
        if (i != s1.length() && s1[i] == s3[k])
            c1 = solver(s1, s2, s3, i + 1, j, k + 1);
        if (j != s2.length() && s2[j] == s3[k])
            c2 = solver(s1, s2, s3, i, j + 1, k + 1);
        return c1 || c2;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        return solver(s1, s2, s3, 0, 0, 0);
    }
};

int main()
{

    return 0;
}