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
ll n, k, a[1000001], ok = 1;
void khoi_tao()
{
    for (ll i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}
void sinh()
{
    ll i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        ok = 0;
    }
    else
    {
        a[i]++;
        for (ll j = i + 1; j < n; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    faster();
    cin >> n >> k;
    khoi_tao();
    string tam = "";
    vector<string> res;
    for (ll i = 1; i <= k; i++)
    {
        ll x;
        cin >> x;
        tam += to_string(x);
    }
    while (ok)
    {
        string tmp = "";
        for (ll i = 1; i <= k; i++)
        {
            tmp += to_string(a[i]);
        }
        res.push_back(tmp);
        sinh();
    }
    reverse(all(res));
    ll cnt = 1;
    for (ll i = 0; i < res.size(); i++)
    {
        if (tam == res[i])
        {
            break;
        }
        cnt++;
    }
    cout << cnt << endl;
}