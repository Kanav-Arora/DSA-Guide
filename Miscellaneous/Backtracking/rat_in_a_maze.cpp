#include <iostream>
#include <fstream>
using namespace std;

bool isPossible(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool Maze(int **arr, int x, int y, int n, int **soln_arr)
{
    if (x == n - 1 && y == n - 1)
    {
        soln_arr[x][y] = 1;
        return true;
    }

    if (isPossible(arr, x, y, n))
    {
        soln_arr[x][y] = 1;
        if (Maze(arr, x + 1, y, n, soln_arr))
        {
            return true;
        }
        if (Maze(arr, x, y + 1, n, soln_arr))
        {
            return true;
        }
        soln_arr[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    ifstream file;
    file.open("input_1.txt");
    string change_line;
    int n, m;
    file >> n >> m;
    int **arr;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    int **soln_arr;
    soln_arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        soln_arr[i] = new int[m];
    }
    getline(file, change_line);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            file >> arr[i][j];
            soln_arr[i][j] = 0;
        }
        getline(file, change_line);
    }

    if (Maze(arr, 0, 0, n, soln_arr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << soln_arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    /*

            Printing maze matrix

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    */

    return 0;
}