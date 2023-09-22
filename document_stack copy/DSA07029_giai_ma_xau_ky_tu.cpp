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
void solve(string s)
{
    stack<char> st;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] != ']')
            st.push(s[i]);
        else
        {
            string res = "";
            while (st.size() && st.top() != '[')
            {
                res = st.top() + res;
                st.pop();
            }
            st.pop();
            ll cnt = 1;
            string dem = "";
            while (st.size() && isdigit(st.top()) == true)
            {
                dem = st.top() + dem;
                st.pop();
            }
            if (dem.size())
                cnt = stoll(dem);
            string ss = "";
            while (cnt--)
            {
                ss += res;
            }
            for (auto x : ss)
                st.push(x);
        }
    }
    string tam = "";
    while (st.size())
    {
        tam = st.top() + tam;
        st.pop();
    }
    cout << tam << endl;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        string s;
        getline(cin, s);
        solve(s);
    }
}