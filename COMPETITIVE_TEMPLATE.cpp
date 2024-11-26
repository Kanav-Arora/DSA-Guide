#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <limits>    // for numeric limits
#include <cmath>     // for mathematical operations
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)       // 0-based loop
#define foc(i, n) for (int i = 0; i <= n; i++)     // 0-based loop inclusive
#define rfo(i, s, e) for (int i = s; i < e; i++)   // Start-to-end exclusive
#define rfoc(i, s, e) for (int i = s; i <= e; i++) // Start-to-end inclusive
#define revfo(i, e) for (int i = e; i >= 0; i--)   // Reverse loop

// Data type shortcuts
#define ll long long
#define pii pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vpii vector<pii>

// Utility macros
#define deb(x) cout << #x << " = " << x << endl;                                  // Debug single variable
#define deb2(x, y) cout << #x << " = " << x << " , " << #y << " = " << y << endl; // Debug two variables
#define pb push_back                                                              // Shortcut for push_back
#define mp make_pair                                                              // Shortcut for make_pair
#define f first                                                                   // Access the first element of a pair
#define s second                                                                  // Access the second element of a pair
#define all(x) x.begin(), x.end()                                                 // Range shortcut for containers
#define sortall(x) sort(all(x))                                                   // Sort an entire container
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)                  // Traverse a container

// Constants
#define PI 3.141592653589793238           // Approximate value of π
#define inf numeric_limits<int>::max()    // Maximum integer value
#define neginf numeric_limits<int>::min() // Minimum integer value

int max(int v1, int v2)
{
    return v1 < v2 ? v2 : v1;
}

// GCD (Greatest Common Divisor) using Euclid's algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM (Least Common Multiple) based on GCD
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

// Modular exponentiation (for large power computations)
ll mod_exp(ll base, ll exp, ll mod)
{
    ll result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    int t = 1;
    cin >> t;

    return 0;
}
