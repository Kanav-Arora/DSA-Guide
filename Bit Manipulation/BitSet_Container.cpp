#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// the limitation is, size must be known before that is size must be constant unlike dynamic sizes for vector etc.

int main()
{
    /*
        Bitset is a bool array but it is optimized in a way that it takes only 1 bit for storing this bool value.
        so size of bitset array is less that bool array of vector<bool>

        This also makes it more optimized in both space and time complextiy terms
    */

    bitset<8> b_e; // defualt constructor initialize with all 0's
    cout << b_e << endl;

    string bit_val = "10101001";
    bitset<8> b1(bit_val);
    cout << "B1 : " << b1 << endl;

    // bitset array can be changed by accessing the elements from right with 0 based indexing
    b1[1] = 1;
    cout << "B1 changed : " << b1 << endl;

    bitset<8> b2(bit_val, 2, 3);
    cout << "B2 : " << b2 << endl;

    string bit_val_2 = "abaabbba";
    bitset<8> b3(bit_val_2, 0, bit_val_2.length(), 'a', 'b');
    cout << "B3 : " << b3 << endl;

    std::bitset<8> b(42);
    std::cout << b.to_string() << endl
              << b.to_string('*') << endl
              << b.to_string('O', 'X') << endl;

    int number_of_1 = b.count();
    int number_of_0 = b.size() - b.count();

    cout << b << " has " << number_of_1 << " ones and "
         << number_of_0 << " zeros" << endl;

    /*
        Test function returns 1 if bit is set else 0
    */

    cout << "bool representation of " << b << " : ";
    for (int i = 0; i < b.size(); i++)
        cout << b.test(i) << " ";
    cout << endl;

    /*
        .any()  returns true if there's atleast 1 set bit
        .none() returns true if there's no set bit

        bset.set()  - sets all bits
        bset.set(pos, b) makes bset[pos] = b

        bset.set(pos) makes bset[pos] = 1

        reset function makes all bits 0

        set8.flip(2) -  flip function flips all bits
    */
}