/*
    An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal. For example, [9, 10], [3, 3, 3], and [9, 7, 5, 3] are arithmetic arrays, while [1, 3, 3, 7], [2, 1, 2], and [1, 2, 4] are not arithmetic arrays.

    Sarasvati has an array of N non-negative integers. The i-th integer of the array is Ai. She wants to choose a contiguous arithmetic subarray from her array that has the maximum length. Please help her to determine the length of the longest contiguous arithmetic subarray.

    Input

    The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Ai.

    Output
    
    For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the length of the longest contiguous arithmetic subarray.
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

    int pd = 0, ans_ind = 0, ans_length = 2, currlength = 2;
    int start_ind = 0;
    for (int i = 1; i <n; i++)
    {
        // cout << "pd: " << pd << " ans_index: " << ans_ind << " ans length: " << ans_length<< endl;
        if (arr[i] - arr[i - 1] == pd)
        {
            currlength++;
        }
        else
        {
            pd = arr[i] - arr[i - 1];
            if(currlength>ans_length)
            {
                ans_length = currlength;

                ans_ind = start_ind;
            }
            start_ind = i-1;
            currlength = 2;
        }
    }
        // cout << "pd: " << pd << " ans_index: " << ans_ind << " ans length: " << ans_length<< endl;

    // cout << "ans_index: " << ans_ind << " ans length: " << ans_length << endl;

    for (int i = 0; i < ans_length; i++)
    {
        cout << arr[ans_ind + i] << " ";
    }

    return 0;
}