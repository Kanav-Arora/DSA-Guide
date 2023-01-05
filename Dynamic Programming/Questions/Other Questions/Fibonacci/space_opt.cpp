#include<iostream>
using namespace std;

int main()
{
    
    int n;
    cin>>n;

    int prev = 1, prev2 = 1;
    int curri;

    for(int i=2; i<=n; i++)
    {
        curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }

    cout<<curri<<endl;

    return 0;
}

// T.C : O(1) and S.C : O(1)