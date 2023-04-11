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
ll uutien(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}
void solve(string s)
{
    string res = "";
    stack<char> st;
    for (auto x : s)
    {
        if (isalpha(x))
        {
            res += x;
        }
        else
        {
            if (x == '(')
            {
                st.push(x);
            }
            else
            {
                if (x == ')')
                {
                    while (!st.empty() && st.top() != '(')
                    {
                        res += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    while (!st.empty() && uutien(st.top()) >= uutien(x))
                    {
                        res += st.top();
                        st.pop();
                    }
                    st.push(x);
                }
            }
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
}
int main()
{
    faster();
    string s;
    cin >> s;
    solve(s);
}