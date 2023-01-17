#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
    bool solver(string s, int i, set<string> &st)
    {
        if (i == s.length())
            return true;
        int ans = false;
        string temp = "";
        for (int j = i; j < s.length(); j++)
        {
            temp += s[j];

            if (st.find(temp) != st.end())
            {
                ans = ans || solver(s, j + 1, st);
            }
            if (ans)
                return ans;
        }
        return ans;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st(wordDict.begin(), wordDict.end());
        return solver(s, 0, st);
    }
};

int main()
{

    return 0;
}