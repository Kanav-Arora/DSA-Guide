/*
    Consider an array “Day” that contains N elements. Write a function “PCC( )” to find the peak day for COVID cases in Noida. The integer array of “Day” having 
    size as N are provided as inputs to PCC( ) from main function. The PCC( ) will return the day of the peak weather condition. The result will be displayed in 
    the main function.

*/


#include<iostream>
#include<vector>
using namespace std;


int findPeak(vector<int> nums)
{
    int low = 0, high = nums.size()-1, mid=0;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if((mid==0 || nums[mid-1]<nums[mid]) && (mid==nums.size()-1 || nums[mid+1]<nums[mid]))
            return nums[mid];
        else if(nums[mid-1]>nums[mid])
            high = mid-1;
        else if(nums[mid+1]>nums[mid])
            low = mid+1;
    }
    return -1;
}

int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start<end)
        {
            int mid1 = start + (end-start)/2;
            int mid2 = mid1 + 1;
            if(nums[mid1]<nums[mid2])
            {
                start = mid2;
            }
            else
                end = mid1;
        }
        return nums[start];
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    while(n--)
    {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    cout<<findPeak(nums)<<endl;
    return 0;
}