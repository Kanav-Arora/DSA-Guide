#include <iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;

        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
        return start;

    else
        return -1;
}

int main()
{

    return 0;
}