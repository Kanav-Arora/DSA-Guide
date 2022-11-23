#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Leetcode Question

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<set<int>> rows(9), cols(9), blocks(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // if board[i][j] entry is '.' then we just continue as we only care about the duplicate values
            if (board[i][j] == '.')
            {
                continue;
            }

            int curr = board[i][j]; // we can get the value at given index to check that if it is already
            // present in set or not

            // here our count function returns 1 if value is already present in row or column or block otherwise it will return 0

            // for block try this formula using pen and paper you will get it..
            if (rows[i].count(curr) || cols[j].count(curr) ||
                blocks[(i / 3) * 3 + j / 3].count(curr))
            {
                return false; // we return false because the value currently we have is already present in set
            }
            // if we don't found the value then after that we must enter this value in our set
            rows[i].insert(curr);
            cols[j].insert(curr);
            blocks[(i / 3 * 3) + j / 3].insert(curr);
        }
    }
    return true; // after loop finishes our control reaches here that means our sudoko is valid...
}

int main()
{

    return 0;
}