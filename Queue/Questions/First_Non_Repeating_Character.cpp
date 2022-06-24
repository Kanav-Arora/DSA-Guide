#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

string NonRepeating(string s)
{
    queue<char> q;
    unordered_map<char, int> count;
    string ans = "";

    for(int i=0; i<s.length(); i++)
    {
        count[s[i]]++;

        q.push(s[i]);


        while(!q.empty())
        {
            // repeating character
            if(count[q.front()]>1)
                q.pop();
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty())
            ans+="#";
    }
    
    return ans;
    
}

int main()
{
    cout<<NonRepeating("ftvbwnimpvvbfvtot");
    return 0;
}