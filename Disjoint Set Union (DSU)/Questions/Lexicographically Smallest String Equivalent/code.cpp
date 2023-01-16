#include <iostream>
#include <vector>
using namespace std;

void swap(char ch1, char ch2)
{
    char temp = ch2;
    ch2 = ch1;
    ch1 = temp;
}

class Solution
{
    char parent[26];

    void make(char ch)
    {
        int ind = ch - 'a';
        parent[ind] = ch;
    }

    char find(char ch)
    {
        int ind = ch - 'a';
        if (parent[ind] == ch)
            return ch;
        return parent[ind] = find(parent[ind]); // path compression
    }

    void Union(char ch1, char ch2)
    {
        char root1 = find(ch1);
        char root2 = find(ch2);

        if (root1 != root2)
        {
            if (root1 > root2)
            {
                swap(root1, root2);
            }
            parent[root2 - 'a'] = root1;
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.length();

        for (int i = 0; i < 26; i++)
            make('a' + i);

        for (int i = 0; i < n; i++)
        {
            int ch1 = s1[i];
            int ch2 = s2[i];

            Union(ch1, ch2);
        }

        int m = baseStr.length();
        string ans = "";
        for (int i = 0; i < m; i++)
        {
            char ch = baseStr[i];
            ans += find(ch);
        }

        return ans;
    }
};

int main()
{

    return 0;
}