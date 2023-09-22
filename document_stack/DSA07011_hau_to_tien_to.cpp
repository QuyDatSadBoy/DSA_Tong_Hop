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
        getline(cin, s);
        stack<string> st;
        for (ll i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
                st.push(string(1, s[i]));
            else
            {
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                st.push(s[i] + top2 + top1);
            }
        }
        cout << st.top() << endl;
    }
}