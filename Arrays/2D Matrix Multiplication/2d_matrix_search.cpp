#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream file;
    file.open("2d_input.txt");
    int n1, m1;
    file >> n1;
    file >> m1;
    int arr[n1][m1];
    string line;
    getline(file, line);
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            file >> arr[i][j];
        }
        getline(file, line);
    }

    int num;
    cout<<"Number you want to search:"<<endl;
    cin>>num;

    int curr_row = 0;
    int curr_col = m1-1;

    while(curr_row<n1 && curr_col>=0)
    {
        // cout<<"row: "<<curr_row<<" col: "<<curr_col<<endl;
        if(arr[curr_row][curr_col]==num)
        {
            cout<<"Number found at: ("<<curr_row<<","<<curr_col<<")"<<endl;
            return 0;
        }
        else
        {
            if(num<=arr[curr_row][curr_col-1])
            {
                curr_col--;
            }
            else
            {
                curr_row++;
            }
        }
    }
    cout<<"number not found"<<endl;
    return 0;
}