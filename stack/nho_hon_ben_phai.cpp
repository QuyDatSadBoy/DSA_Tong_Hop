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
    ll a[n], b[n], c[n];
    for (auto &x : a)
        cin >> x;
    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (a[i] > a[st.top()])
            {
                while (!st.empty() && a[i] > a[st.top()])
                {
                    ll top = st.top();
                    st.pop();
                    b[top] = i;
                }
                st.push(i);
            }
            else
                st.push(i);
        }
    }
    while (!st.empty())
    {
        ll top = st.top();
        st.pop();
        b[top] = -1;
    }
    // nho hon
    for (ll i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(i);
        else
        {
            if (a[i] < a[st.top()])
            {
                while (!st.empty() && a[i] < a[st.top()])
                {
                    ll top = st.top();
                    st.pop();
                    c[top] = i;
                }
                st.push(i);
            }
            else
                st.push(i);
        }
    }
    while (!st.empty())
    {
        ll top = st.top();
        st.pop();
        c[top] = -1;
    }
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == -1 || c[b[i]] == -1)
        {
            cout << -1 << " ";
        }
        else
            cout << a[c[b[i]]] << " ";
    }
    cout << endl;
}