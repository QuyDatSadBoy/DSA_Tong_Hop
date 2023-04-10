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

int main()
{
    faster();
    ll n;
    cin >> n;
    ll a[n], chan = 0, le = 0, ok = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            le++;
        }
        else
            chan++;
    }
    if (chan % 2 == 0)
    {
        cout << "YES" << endl;
        return 0;
    }
    else
    {
        sort(a, a + n);
        for (ll i = 1; i < n; i++)
        {
            if (abs(a[i - 1] - a[i]) == 1)
            {
                ok = 1;
                break;
            }
        }
        if (ok == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}