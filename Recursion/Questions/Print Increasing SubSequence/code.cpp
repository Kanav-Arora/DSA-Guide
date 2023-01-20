#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
    void solver(vector<int> &nums, int ind, int prev, vector<int> temp, set<vector<int>> &ans)
    {
        if (ind == nums.size())
        {
            if (temp.size() >= 2)
                ans.insert(temp);
            return;
        }

        solver(nums, ind + 1, prev, temp, ans);

        if (prev == -1 || nums[ind] >= nums[prev])
        {
            temp.push_back(nums[ind]);
            solver(nums, ind + 1, ind, temp, ans);
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> ans;
        vector<int> temp;
        solver(nums, 0, -1, temp, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};

int main()
{

    return 0;
}