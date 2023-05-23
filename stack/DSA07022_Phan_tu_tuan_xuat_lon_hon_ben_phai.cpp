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
        map<ll, ll> mp;
        for (auto &x : a)
        {
            cin >> x;
            mp[x]++;
        }
        stack<ll> st;
        for (ll i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(i);
            else
            {
                if (mp[a[i]] <= mp[a[st.top()]])
                    st.push(i);
                else
                {
                    while (!st.empty() && mp[a[i]] > mp[a[st.top()]])
                    {
                        ll top = st.top();
                        st.pop();
                        c[top] = a[i];
                    }
                    st.push(i);
                }
            }
        }
        while (!st.empty())
        {
            ll top = st.top();
            st.pop();
            c[top] = -1;
        }
        for (ll i = 0; i < n; i++)
            if (c[i] != -1)
                cout << c[i] << " ";
            else
                cout << -1 << " ";
        cout << endl;
    }
}