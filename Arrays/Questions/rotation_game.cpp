#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        void reverse(vector<int>& nums, int low, int high)
        {
            while(low<high)
            {
                swap(nums[low],nums[high]);
                low++;
                high--;
            }
        }
        void right(vector<int>& nums, int k)
        {
            int n = nums.size();
            reverse(nums,0,n-k-1);
            reverse(nums,n-k,n-1);
            reverse(nums,0,n-1);
        }
        void left(vector<int>& nums, int k)
        {
            int n = nums.size();
            reverse(nums,0,k-1);
            reverse(nums,k,n-1);
            reverse(nums,0,n-1);
        }
        void rotate(vector<int>& nums, int k, vector<int> rotations)
        {
            for(int i=0; i<rotations.size(); i++)
            {
                if(rotations[i]==1)
                {
                    left(nums,k);
                    display(nums);
                }
                else if(rotations[i]==0)
                {
                    right(nums,k);
                    display(nums);
                }
            }
        }    
        void display(vector<int> nums)
        {
            for(auto i : nums)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    int numbers[] = {1,2,3,4,5,6,7};
    vector<int> nums;
    for(auto i : numbers)
    {
        nums.push_back(i);
    }
    int rot[] = {1,1,1,0,0,1,1};
    vector<int> rotations;
    for(auto i : rot)
    {
        rotations.push_back(i);
    }
    int k = 3;
    Solution s;
    s.rotate(nums, k, rotations);

    for(auto i : nums)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}