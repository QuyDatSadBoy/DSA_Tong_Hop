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
bool isgood(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
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
        bool ok = 0;
        stack<char> st;
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            if (!st.empty() && s[i] == ')')
            {
                bool ok2 = false;
                while (st.top() != '(')
                {
                    char top = st.top();
                    st.pop();
                    if (isgood(top))
                        ok2 = 1; // co dau va khong thua
                }
                st.pop();
                if (ok2 == 0)
                {
                    // thua dau ngaoc
                    ok = 1;
                    break;
                }
            }
            else
                st.push(s[i]);
        }
        if (ok == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}