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
ll n, ok = 1;
string s;
void sinh()
{
    ll i = s.size() - 1;
    while (i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if (i == -1)
    {
        ok = 0;
    }
    else
    {
        s[i] = '1';
    }
}
bool check()
{
    stack<char> st;
    // 0 la dau mo ngoac
    // 1 la dau dong ngoac
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty();
}
int main()
{
    faster();
    cin >> n;
    string tam(n, '0');
    s = tam;
    ll check_1 = false;
    while (ok)
    {
        if (check())
        {
            for (ll i = 0; i < s.size(); i++)
            {
                if (s[i] == '0')
                    cout << "(";
                else
                    cout << ")";
            }
            cout << endl;
            check_1 = true;
        }
        sinh();
    }
    if (!check_1)
    {
        cout << "NOT FOUND" << endl;
    }
}