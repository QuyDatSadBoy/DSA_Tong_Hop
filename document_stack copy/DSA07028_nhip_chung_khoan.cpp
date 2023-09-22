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
        ll n;
        cin >> n;
        ll a[n], c[n];
        for (auto &x : a)
            cin >> x;
        stack<ll> st;
        for (ll i = 0; i < n; i++)
        {
            while (!st.empty() && a[i] >= a[st.top()])
            {
                st.pop();
            }
            if (st.size())
                c[i] = i - st.top();
            else
                c[i] = i + 1;
            st.push(i);
        }
        for (ll i = 0; i < n; i++)
            cout << c[i] << " ";
        cout << endl;
    }
}