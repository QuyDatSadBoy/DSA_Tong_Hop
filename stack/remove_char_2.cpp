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
    ll k;
    cin >> k;
    stack<pair<char, ll>> st;
    for (ll i = 0; i < s.size(); i++)
    {
        if (st.empty())
            st.push({s[i], 1});
        else
        {
            if (s[i] == st.top().first)
            {
                if (st.top().second + 1 == k)
                {
                    st.pop();
                }
                else
                {
                    st.top().second++;
                }
            }
            else
                st.push({s[i], 1});
        }
    }
    string res = "";
    while (!st.empty())
    {
        for (ll i = st.top().second; i >= 1; i--)
            res += st.top().first;
        st.pop();
    }
    reverse(all(res));
    if (res == "")
        cout << "EMPTY" << endl;
    else
        cout << res << endl;
    return 0;
}