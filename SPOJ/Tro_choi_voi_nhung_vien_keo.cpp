#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) ((x >> i) & 1)
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll ok = 1, cnt1 = 0, cnt2 = 0;
        bool check = false;
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                cnt1++;
            else
                cnt2++;
        }
        if (cnt1 == 0)
        {
            cout << "ONE" << endl;
        }
        else
        {
            if (cnt2 == 0)
            {
                if (n % 2 == 1)
                    cout << "ONE" << endl;
                else
                    cout << "TWO" << endl;
            }
            else
            {
                ll tam = 1;
                for (ll i = 0; i < n - 1; i++)
                {
                    if (a[i] == 1)
                    {
                        if (tam == 1)
                            tam = 2;
                        else
                            tam = 1;
                    }
                }
                if (tam == 1)
                    cout << "ONE" << endl;
                else
                    cout << "TWO" << endl;
            }
        }
    }
}