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
set<string> se;
queue<string> qe;
vector<string> v;
void Delete(string s)
{
    stack<ll> st;
    vector<pair<ll, ll>> res; // luu index cap ngoac
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (s[i] == ')')
            {
                res.push_back({st.top(), i});
                st.pop();
            }
        }
    }
    for (auto &x : res)
    {
        string f = s;
        f = f.erase(x.first, 1);
        f = f.erase(x.second - 1, 1);
        if (!se.count(f))
        {
            se.insert(f);
            qe.push(f);
        }
    }
}
void solve()
{
    string s;
    getline(cin, s);
    Delete(s);
    while (qe.size())
    {
        string top = qe.front();
        qe.pop();
        v.push_back(top);
        Delete(top);
    }
    sort(all(v));
    for (auto &x : v)
        cout << x << endl;
}
int main()
{
    faster();
    solve();
}