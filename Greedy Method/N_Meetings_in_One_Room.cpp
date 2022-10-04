#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Meeting
{
    int id;
    int start;
    int end;
};

bool comp(Meeting &m1, Meeting&m2)
{
    if(m1.end==m2.end)
        return m1.id<m2.id;
    return m1.end<m2.end;
}

vector<int> NMeetings(vector<Meeting> &meetings, int n)
{
    sort(meetings.begin(), meetings.end(), comp);
    vector<int> ans;

    int lastmeeting = -1;
    for(int i=0; i<n; i++)
    {
        if(meetings[i].start>lastmeeting)
        {
            lastmeeting = meetings[i].end;
            ans.push_back(meetings[i].id);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<Meeting> v;

    for(int i=0; i<n; i++)
    {
        int id, start, end;
        cin>>id>>start>>end;

        Meeting m;
        m.start = start;
        m.id = id;
        m.end = end;

        v.push_back(m);
    }

    vector<int> ans = NMeetings(v,n);

    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}


/*

Input:
6
1 1 2
2 0 6
3 3 4
4 8 9
5 5 7
6 8 9

Output:
1 3 5 4

*/