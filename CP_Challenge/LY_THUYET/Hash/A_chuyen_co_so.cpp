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
    ll t, k;
    string n;
    cin >> t;
    cin.ignore(1);
    cin >> n >> k;
    if (t == 1) // chuyen n thanh he co so k
    {
        stack<ll> st;
        ll value = stoll(n);
        while (value)
        {
            st.push(value % k);
            value /= k;
        }
        while (st.size())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    if (t == 2) // chuyen n ve he co so 10
    {
        ll res = 0;
        for (ll i = 0; i < n.size(); i++)
        {
            res = res * k + (n[i] - '0');
        }
        cout << res << endl;
    }
}