#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solver(string word1, string word2, int i, int j)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (word1[i] == word2[j])
            return 0 + solver(word1, word2, i - 1, j - 1);

        int insert = 1 + solver(word1, word2, i, j - 1);
        int del = 1 + solver(word1, word2, i - 1, j);
        int replace = 1 + solver(word1, word2, i - 1, j - 1);
        return min(insert, min(del, replace));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        return solver(word1, word2, n - 1, m - 1);
    }
};

int main()
{

    return 0;
}