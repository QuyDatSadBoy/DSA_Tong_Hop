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
    string s;
    cin >> s;
    stack<char> st;
    ll ans = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if (st.top() == '(' && s[i] == ')')
            {
                ans += 2;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    cout << (s.size() - ans) / 2 << endl;
}