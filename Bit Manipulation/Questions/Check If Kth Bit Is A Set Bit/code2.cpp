#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    bitset<8> b("00001000");
    b >>= 3;
    bitset<8> c(1);
    cout << ((b & c) == c) << endl;
    return 0;
}