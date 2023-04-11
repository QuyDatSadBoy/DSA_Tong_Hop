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
void solve(string s)
{
    stack<string> st;
    for (ll i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            st.push(string(1, s[i]) + top2 + top1);
        }
    }
    cout << st.top() << endl;
}
int main()
{
    faster();
    string s;
    cin >> s;
    solve(s);
}