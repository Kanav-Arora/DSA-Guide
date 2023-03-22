#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n > 0)
    {
        if ((n & 1) == 1)
            count++;
        n >>= 1;
    }
    cout << count << endl;
    return 0;
}