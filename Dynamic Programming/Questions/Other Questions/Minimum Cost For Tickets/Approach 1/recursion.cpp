#include <iostream>
#include <vector>
using namespace std;

int solver(vector<int> &days, int ind, int d, vector<int> &costs)
{
    if (ind == days.size())
        return 0;
    if (days[ind] <= d)
        return solver(days, ind + 1, d, costs);
    int call1 = costs[0] + solver(days, ind + 1, days[ind], costs);
    int call2 = costs[1] + solver(days, ind + 1, days[ind] + 6, costs);
    int call3 = costs[2] + solver(days, ind + 1, days[ind] + 29, costs);

    return min(call1, min(call2, call3));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return solver(days, 0, 0, costs);
}

int main()
{
    return 0;
}