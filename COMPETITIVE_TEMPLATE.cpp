#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define gc getchar_unlocked;
#define fo(i, n) for (int i = 0; i < n; i++)
#define foc(i, n) for (int i = 0; i <= n; i++)
#define rfo(i, s, e) for (int i = s; i < e; i++)
#define rfoc(i, s, e) for (int i = s; i <= e; i++)
#define revfo(i, e) for (int i = e; i >= 0; i--)
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << " , " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.141592653589793238
#define inf numeric_limits<int>::max()
#define neginf numeric_limits<int>::min()

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpii;

int max(int v1, int v2)
{
    return v1 < v2 ? v2 : v1;
}

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        cout << inf << endl;
    }
    return 0;
}