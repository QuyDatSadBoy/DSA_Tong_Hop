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
ll max_area(ll a[], ll n)
{
    ll res = int(-1e9);
    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (a[i] < a[st.top()])
            {
                while (!st.empty() && a[i] < a[st.top()])
                {
                    ll top = st.top();
                    st.pop();
                    if (st.empty())
                    {
                        res = max(res, a[top] * (i));
                    }
                    else
                        res = max(res, a[top] * (i - st.top() - 1));
                }
                st.push(i);
            }
            else
            {
                st.push(i);
            }
        }
    }
    while (!st.empty())
    {
        ll top = st.top();
        st.pop();
        if (st.empty())
        {
            res = max(res, a[top] * (n));
        }
        else
            res = max(res, a[top] * (n - st.top() - 1));
    }
    return res;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    ll a[n][m], f[n][m];
    ms(f);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (i == 0)
            {
                f[i][j] = a[i][j];
            }
            else
            {
                if (a[i][j] != 0)
                {
                    f[i][j] = a[i][j] + f[i - 1][j];
                }
                else
                    f[i][j] = 0;
            }
        }
    }
    ll ans = int(-1e9);
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, max_area(f[i], m));
    }
    cout << ans << endl;
    return 0;
}