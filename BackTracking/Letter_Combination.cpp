#include <iostream>
#include <vector>
using namespace std;

void solve(string digits, int i, int n, string comb, vector<string> &ans)
{
    if (i == n)
    {
        ans.push_back(comb);
        return;
    }

    solve(digits, i + 1, n, comb + char(((digits[i] - '0') - 2) * 3), ans);
    solve(digits, i + 1, n, comb + char(((digits[i] - '0') - 2) * 3 + 1), ans);
    solve(digits, i + 1, n, comb + char(((digits[i] - '0') - 2) * 3 + 2), ans);
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    int n = digits.length();
    if (n == 0)
        return ans;
    solve(digits, 0, n, "", ans);

    return ans;
}

int main()
{
    vector<string> ans = letterCombinations("23");
    for(auto i: ans)
        cout<<i<<endl;
    return 0;
}