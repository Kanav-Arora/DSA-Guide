#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    bitset<8> b("00000000");
    bitset<8> c(1 << 3);
    cout << ((b & c) == c) << endl;
    return 0;
}