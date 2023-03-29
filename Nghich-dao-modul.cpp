#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

ll x, y, g;
void extend_gcd(ll a, ll b)
{
    if (b == 0)
    {
        g = a;
        x = 1;
        y = 0;
    }
    else
    {
        extend_gcd(b, a % b);
        ll tam = x;
        x = y;
        y = tam - a / b * y;
    }
}
int main()
{
    faster();
    extend_gcd(24, 17);
    cout << g << " " << x << " " << y << endl;
}