/*
        * Kick Start
        Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is Vi. A day is record breaking if it satisfies both of the following conditions:
The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
Note that the very first day could be a record breaking day!
Please help Isyana find out the number of record breaking days.


Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Vi.
Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of record breaking days.

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    int record = arr[0];
    int record_ind = 0;
    for (int i = 1; i < n - 1; i++)
    {
        bool cond1 = true;
        bool cond2 = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                cond1 = false;
            }
        }
        if (arr[i] < arr[i + 1])
        {
            cond2 = false;
        }

        if (cond1 == true && cond2 == true && arr[i] > record)
        {
            record = arr[i];
            record_ind = i;
        }
    }

    cout << "record ele: " << record << endl;
    cout << "record index: " << record_ind << endl;
    return 0;
}