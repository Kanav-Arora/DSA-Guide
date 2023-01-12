#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solver(int open, int close, string val, vector<string> &ans)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(val);
            return;
        }
        if (open < 0 || close < 0)
            return;

        solver(open - 1, close + 1, val + '(', ans);
        if (close > 0)
            solver(open, close - 1, val + ')', ans);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        solver(n, 0, "", ans);
        return ans;
    }
};

int main()
{

    return 0;
}