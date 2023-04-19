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
struct idex
{
    ll x, y;
};
ll f[1000001] = {0};
int main()
{
    // faster();
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        stack<idex> st;
        ll cnt = 0;
        string res = "";
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push({++cnt, i});
            }
            else
            {
                if (s[i] == ')')
                {
                    auto top = st.top();
                    st.pop();
                    f[i] = f[top.y] = top.x;
                }
                else
                    continue;
            }
        }
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                cout << f[i] << " ";
                f[i] = 0;
            }
        }
        cout << endl;
    }
}