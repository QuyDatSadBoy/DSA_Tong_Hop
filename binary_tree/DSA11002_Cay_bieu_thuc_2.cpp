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
    while (t--)
    {
        ll n;
        cin >> n;
        cin.ignore(1);
        string s, a = "";
        queue<ll> qe;
        getline(cin, s);
        for (ll i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (a.size() >= 1)
                    qe.push(stoll(a));
                a = "";
                continue;
            }
            if (isdigit(s[i]))
            {
                a = s[i] + a;
                continue;
            }
            ll top1 = qe.front();
            qe.pop();
            ll top2 = qe.front();
            qe.pop();
            if (s[i] == '+')
                qe.push(top2 + top1);
            if (s[i] == '-')
                qe.push(top2 - top1);
            if (s[i] == '*')
                qe.push(top2 * top1);
            if (s[i] == '/')
                qe.push(top2 / top1);
        }
        cout << qe.front() << endl;
    }
}