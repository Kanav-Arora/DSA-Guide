#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>> maze,int n, vector<vector<bool>> &visited, int i, int j, string path, vector<string> &ans)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(path);
        return;
    }

    visited[i][j] = 1;
    if(i+1<n &&maze[i+1][j]==1 && visited[i+1][j]!=1)
        solve(maze,n,visited,i+1,j,path+'D',ans);
    if(j-1>-1 && maze[i][j-1]==1 && visited[i][j-1]!=1)
        solve(maze,n,visited,i,j-1,path+'L',ans);
    if(j+1<n && maze[i][j+1]==1 && visited[i][j+1]!=1)
        solve(maze,n,visited,i,j+1,path+'R',ans);
    if(i-1>-1 && maze[i-1][j]==1 && visited[i-1][j]!=1)
        solve(maze,n,visited,i-1,j,path+'U',ans);

    visited[i][j] = 0;
}

vector<string> SearchMaze(vector<vector<int>> maze, int n)
{
    vector<string> ans;
    if(maze[0][0]==0)
        return ans;

    vector<vector<bool>> visited (n,vector<bool>(n,0));

    string path = "";

    solve(maze,n,visited,0,0,path,ans);

    return ans;
}

int main()
{
    vector<vector<int>> maze = {{1,1},{1,1}};
    vector<string> ans = SearchMaze(maze,2);

    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}