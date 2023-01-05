#include <iostream>
#include <vector>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();

    int prev2 = nums[0], prev1 = max(nums[0],nums[1]),curr = max(prev1,prev2);

    for(int i=2; i<n; i++)
    {
        int pick = nums[i];
        if(i>1)
            pick+=prev2;
        int dont = prev1;

        curr  = max(pick,dont);

        prev2 = prev1; prev1 = curr;
    }

    return curr;
}

int main()
{

    return 0;
}

// T.C : O(N) and S.C : O(1)