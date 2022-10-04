#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        priority_queue<pair<int,pair<int,int>>> q;
        
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            q.push({arr[i].profit,{arr[i].id,arr[i].dead}});
            maxi = max(maxi,arr[i].dead);
        }
        
        vector<int> jobs(maxi+1,-1);
        int total = 0;
        int num = 0;
        while(!q.empty())
        {
            pair<int,pair<int,int>> p = q.top();
            q.pop();
            int id,dead,profit;
            id = p.second.first;
            dead = p.second.second;
            profit = p.first;
            
            while(dead>0)
            {
                if(jobs[dead]==-1)
                {
                    jobs[dead] = id;
                    total += profit;
                    num++;
                    break;
                }
                dead--;
            }
        }
        
        vector<int> ans = {num,total};
        return ans;
    } 
};

int main()
{
    
    return 0;
}


/*

Input:

4
1 4 20 2 1 10 3 1 40 4 1 30


Output:

2 60

*/