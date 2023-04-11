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

ll pow_mod(ll a, ll b, ll m)
{
    if (b == 0)
    {
        return 1;
    }
    ll tam = pow_mod(a, b / 2, m);
    if (b & 1)
        return (tam % m) * (tam % m) % m * (a % m) % m;
    else
        return (tam % m) * (tam % m) % m;
}
int main()
{
    faster();
    extend_gcd(24, 17);
    cout << g << " " << x << " " << y << endl;
    if (g != 1)
    {
        cout << "khong ton tai nghich dao modul" << endl;
    }
    else
    {
        cout << "nghich dao modul la :" << x << endl;
    }

    // cách 2 là : nếu p là số nguyên tố và a không chia hết cho p thì nghịch đảo modul của a và b là a^(p-2)%p nhé
    // vd a=2,p=11;
    cout << pow_mod(2, 11 - 2, 11) << endl;
}
