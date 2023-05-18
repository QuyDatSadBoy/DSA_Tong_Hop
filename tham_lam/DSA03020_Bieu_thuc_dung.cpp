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
    cin.ignore(1);
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        ll ans = 0;
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
                st.push(s[i]);
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    ll j = i;
                    while (s[j] == ']')
                        j++;
                    swap(s[i], s[j]);
                    ans += j - i;
                    st.push(s[i]);
                }
            }
        }
        cout << ans << endl;
    }
}