#include <iostream>
#include <vector>
using namespace std;

int solver(int n, vector<int> &days, int ind, vector<int> &costs)
{
    if (ind >= n)
        return 0;

    int call1 = costs[0] + solver(n, days, ind + 1, costs);
    int i;
    for (i = ind; i < n && days[i] < days[ind] + 7; i++)
        ;
    int call2 = costs[1] + solver(n, days, i, costs);
    for (i = ind; i < n && days[i] < days[ind] + 30; i++)
        ;
    int call3 = costs[2] + solver(n, days, i, costs);

    return min(call1, min(call2, call3));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return solver(days.size(), days, 0, costs);
}

int main()
{

    return 0;
}