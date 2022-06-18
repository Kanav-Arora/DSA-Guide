// Amazon


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int celebrity(vector<vector<int> > M, int n)
{
    stack<int> s;
    for(int i=0; i<n; i++)
        s.push(i);
    
    while(s.size()!=1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(M[a][b]==1)
            s.push(b);

        else if(M[b][a]==1)
            s.push(a);
    }
    int celeb = s.top();
    int flag = true;

    for(int i=0; i<n; i++)
    {
        if(M[i][celeb]==0 && i!=celeb)
            flag = false;
    }

    for(int i=0; i<n; i++)
    {
        if(M[celeb][i]==1)
            flag = false;
    }

    if(flag==false)
        return -1;
    
    return celeb;
}


int main()
{
    int n = 3;
    vector<vector<int> > v = {{0,0,0},{1,0,0},{1,0,0}};
    cout<<celebrity(v,n);
    return 0;
}