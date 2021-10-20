/*
                    Spiral Order Matrix Traversal in a 2D Array
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream file;
    file.open("2d_input.txt");
    int n,m;
    file >> n;
    file >> m;
    int arr[n][m];
    string line;
    getline(file,line);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            file >> arr[i][j];
        }
        getline(file, line);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    int start_row = 0;
    int start_column = 0; 
    int end_row = n-1;
    int end_column = m-1;

    while(start_row<=end_row && start_column<=end_column)
    {
        for(int i=start_column; i<=end_column; i++)
        {
            cout<<arr[start_row][i]<<" ";
        }
        cout<<endl;
        start_row++;
        for(int i=start_row; i<=end_row; i++)
        {
            cout<<arr[i][end_column]<<" ";
        }
        cout<<endl;
        end_column--;
        for(int i=end_column; i>=start_column; i--)
        {
            cout<<arr[end_row][i]<<" ";
        }
        cout<<endl;
        end_row--;
        for(int i=end_row; i>=start_row; i--)
        {
            cout<<arr[i][start_column]<<" ";
        }
        cout<<endl;
        start_column++;
    }

    return 0;
}