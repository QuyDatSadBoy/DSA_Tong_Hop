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
    stack<char> st1, st2;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '<')
        {
            if (st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else
        {
            if (s[i] == '>')
            {
                if (st2.size())
                {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else
            {
                if (s[i] == '-')
                {
                    if (st1.size())
                    {
                        st1.pop();
                    }
                }
                else
                    st1.push(s[i]);
            }
        }
    }
    while (st1.size())
    {
        st2.push(st1.top());
        st1.pop();
    }
    while (st2.size())
    {
        cout << st2.top();
        st2.pop();
    }
}