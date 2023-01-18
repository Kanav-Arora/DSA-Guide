#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int max(int a, int b)
    {
        return a < b ? b : a;
    }

public:
    vector<int> lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);

        int ans = 0;
        int lastind = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }

            if (dp[i] > ans)
            {
                ans = dp[i];
                lastind = i;
            }
        }

        vector<int> res;
        int i = lastind;

        while (i >= 0 && hash[i] != i)
        {
            res.push_back(nums[i]);
            i = hash[i];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(11);
    v.push_back(1);
    v.push_back(16);
    v.push_back(18);
    Solution s;
    vector<int> res = s.lengthOfLIS(v);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}