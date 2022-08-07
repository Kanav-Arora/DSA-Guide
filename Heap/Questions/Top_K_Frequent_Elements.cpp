#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<iterator>
using namespace std;


/*
    Leetcode: 347

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/

class comp
{
  public:
    bool operator()(const pair<int,int> a, const pair<int,int> b)
    {
        return a.first>b.first;
    }
};


vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mapping;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> minHeap;  // freq, number
        
        for(int i=0; i<nums.size(); i++)
        {
            mapping[nums[i]]++;
        }
        
        int i=0;
        map<int,int>::iterator it;
        it = mapping.begin(); 
        while(it!=mapping.end() && i<k)
        {
            minHeap.push({it->second, it->first});
            it++; i++;
        }
        
        while(it!=mapping.end())
        {
            if(it->second>minHeap.top().first)
            {
                minHeap.pop();
                minHeap.push({it->second, it->first});
                it++;
            }
            else
                it++;
        }
        
        vector<int> res;
        for(int i=0; i<k; i++)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
}

int main()
{
    
    return 0;
}