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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll max = -1;
    stack<ll> st;
    for (ll i = n - 1; i >= 0; i--)
    {
        st.push(v[i]);
    }
    while (st.size())
    {
        if (st.size() >= 2)
        {
            ll top1 = st.top();
            st.pop();
            ll top2 = st.top();
            st.pop();
            if (max == top1)
            {
                top1++;
            }
            if (top1 == top2)
            {
                if (st.size())
                {
                    if (top2 < st.top())
                        max = top2 + 1;
                    else
                        st.push(top2);
                }
                else
                    max = top2 + 1;
            }
            else
                st.push(top2);
        }
        else
        {
            ll top = st.top();
            st.pop();
            if (top == max)
                max = top + 1;
        }
    }
    cout << max << endl;
}