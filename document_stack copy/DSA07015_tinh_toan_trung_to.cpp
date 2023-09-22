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
ll value1(string c)
{
    if (c == "^")
        return 3;
    if (c == "/" || c == "*")
        return 2;
    if (c == "+" || c == "-")
        return 1;
    return 0;
}
vector<string> converse(vector<string> v)
{
    vector<string> res;
    stack<string> st;
    for (ll i = 0; i < v.size(); i++)
    {
        if (isdigit(v[i][0]))
        {
            res.push_back(v[i]);
        }
        else
        {
            if (v[i] == "(")
                st.push(v[i]);
            else
            {
                if (v[i] == ")")
                {
                    while (st.size() && (st.top() != "("))
                    {
                        res.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    while (st.size() && value1(st.top()) >= value1(v[i]))
                    {
                        res.push_back(st.top());
                        st.pop();
                    }
                    st.push(v[i]);
                }
            }
        }
    }
    while (st.size())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}
ll calc(ll x, ll y, string c)
{
    if (c == "+")
        return x + y;
    if (c == "-")
        return x - y;
    if (c == "*")
        return x * y;
    if (c == "/")
        return (ll)x / y;
    return 0;
}
ll value(vector<string> v)
{
    stack<ll> st;
    for (ll i = 0; i < v.size(); i++)
    {
        if (isdigit(v[i][0]))
        {
            st.push(stoll(v[i]));
        }
        else
        {
            ll top1 = st.top();
            st.pop();
            ll top2 = st.top();
            st.pop();
            ll res = calc(top2, top1, v[i]);
            st.push(res);
        }
    }
    return st.top();
}
int main()
{
    // faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        string s;
        getline(cin, s);
        vector<string> v;
        for (ll i = 0; i < s.size(); i++)
        {

            if (isdigit(s[i]))
            {
                string tam = "";
                while (i < s.size() && isdigit(s[i]))
                {
                    tam += s[i];
                    i++;
                }
                v.push_back(tam);
                i--;
            }
            else
                v.push_back(string(1, s[i]));
        }
        v = converse(v);
        cout << value(v) << endl;
    }
}