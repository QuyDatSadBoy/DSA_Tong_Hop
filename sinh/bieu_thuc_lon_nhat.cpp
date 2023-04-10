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
ll n, ok = 1;
string s;
void sinh()
{
    ll i = s.size();
    while (i >= 1 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if (i == 0)
    {
        ok = 0;
    }
    else
        s[i] = '1';
}
int main()
{
    faster();
    n = 4;
    string tam(n - 1, '0');
    string s = tam;
    ll a[n];
    for (ll i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    ll sum = a[0], res = -1;
    while (ok)
    {
        // 0 la cong
        // 1 la tru
        for (ll i = 1; i <= 3; i++)
        {
            if (s[i] == '0')
            {
                sum += a[i];
            }
            else
                sum -= a[i];
        }
        res = max(sum, res);
        sinh();
    }
    cout << res << endl;
}