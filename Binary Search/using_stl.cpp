#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr({1, 4, 4, 4, 4, 9, 9, 10, 11});
    int ind = lower_bound(arr.begin(), arr.end(), 4) - arr.begin();
    bool res = binary_search(arr.begin(), arr.end(), 4);
    cout << "Exists: " << res << endl;
    cout << ind << endl;
    return 0;
}