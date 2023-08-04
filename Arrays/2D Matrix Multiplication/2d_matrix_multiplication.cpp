/*
                    2D Matrix Multiplication
*/

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
    int arr1[n1][m1];
    string line;
    getline(file, line);
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            file >> arr1[i][j];
        }
        getline(file, line);
    }

    int n2, m2;
    file >> n2;
    file >> m2;
    int arr2[n2][m2];
    getline(file, line);
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            file >> arr2[i][j];
        }
        getline(file, line);
    }
    file.close();


    int ans[n1][m2];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            ans[i][j] =0;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            int sum=0;
            for(int k=0; k<n2; k++)
            {
                sum+=arr1[i][k]*arr2[k][j];
            }
            ans[i][j] = sum;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}