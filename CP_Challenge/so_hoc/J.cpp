#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int main()
{
    faster();
    ll n;
    cin >> n;
    if (n < 3)
        cout << n << endl;
    else if (n % 6 == 0)
    {
        cout << (n - 1) * (n - 2) * (n - 3) << endl;
    }
    else if (n % 2)
    {
        cout << n * (n - 1) * (n - 2) << endl;
    }
    else
        cout << n * (n - 1) * (n - 3) << endl;
}