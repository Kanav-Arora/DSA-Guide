#include <iostream>
#include <vector>
using namespace std;

// These functions are defined in gcc compiler and they have a best case time complexity of O(1)
// and an average case time complexity of O(log_2 k) where k is the position of set bit

int main()
{
    cout << __builtin_clz(5) << endl; // count no of zero bits at the beginning of a number

    // use __builtin_clzl for long int and __builtin_clzll for long long and same for other functions

    cout << __builtin_ctz(5) << endl; // count no of zero bits at the end of a number

    cout << __builtin_popcount(5) << endl; // number of 1's in bit

    cout << __builtin_parity(5) << endl; // returns 1 if no of 1's in number is odd else 0
    return 0;
}