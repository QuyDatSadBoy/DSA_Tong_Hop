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
void solve(ll a[], ll n)
{
    ll res = 0;
    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(i);
        else
        {
            if (a[i] >= a[st.top()])
                st.push(i);
            else
            {
                ll cnt = 0;
                while (st.size() && a[i] < a[st.top()])
                {
                    ll top = st.top();
                    st.pop();
                    ll dem;
                    if (!st.size())
                        dem = i;
                    else
                        dem = i - st.top() - 1;
                    if (a[top] <= dem)
                        res = max(res, min(a[top], dem));
                }
                st.push(i);
            }
        }
    }
    while (st.size())
    {
        ll top = st.top();
        st.pop();
        ll dem;
        if (!st.size())
            dem = n;
        else
            dem = n - st.top() - 1;
        if (a[top] <= dem)
            res = max(res, min(a[top], dem));
    }
    cout << res << endl;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (auto &x : a)
            cin >> x;
        solve(a, n);
    }
}