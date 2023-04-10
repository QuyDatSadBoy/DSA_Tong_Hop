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
ll n, a[1000001], ok = 1, cnt = 1;
void sinh()
{
    ll i = cnt;
    while (a[i] == 1 && i >= 1)
    {
        i--;
    }
    if (i == 0)
        ok = 0;
    else
    {
        a[i]--;
        ll dem = cnt - i + 1;
        cnt = i;
        ll res = dem / a[i];
        ll r = dem % a[i];
        if (res > 0)
        {
            for (ll h = 0; h < res; h++)
            {
                a[++cnt] = a[i];
            }
        }
        if (r)
        {
            a[++cnt] = r;
        }
    }
}
int main()
{
    // faster();
    cin >> n;
    a[1] = n;
    ll t = 10;
    while (ok)
    {
        for (ll i = 1; i <= cnt; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
}