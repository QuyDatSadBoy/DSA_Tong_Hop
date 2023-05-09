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
    string s;
    cin >> s;
    int cnt = 0, res = 0;
    stack<pair<char, int>> st;
    st.push({'*', 0});
    for (char &i : s)
    {
        if (st.size() && ((i == ')' && st.top().first == '(') || (i == ']' && st.top().first == '[')))
        {
            st.pop();
            if (st.size())
                res = max(res, cnt - st.top().second);
        }
        else
        {
            cnt += i == '[';
            st.push({i, cnt});
        }
    }
    cout << res << endl;
}