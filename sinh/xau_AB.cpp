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
ll n, a[1000001], ok = 1;
void khoi_tao()
{
    for (ll i = 0; i < n; i++)
        a[i] = 0;
}
void sinh()
{
    ll i = n - 1;
    while (a[i] == 1 && i >= 0)
    {
        a[i] = 0;
        i--;
    }
    if (i == -1)
    {
        ok = 0;
    }
    else
        a[i] = 1;
}
int main()
{
    faster();
    cin >> n;
    khoi_tao();
    while (ok)
    {
        for (ll i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                cout << "B";
            }
            else
                cout << "A";
        }
        cout << endl;
        sinh();
    }
    return 0;
}