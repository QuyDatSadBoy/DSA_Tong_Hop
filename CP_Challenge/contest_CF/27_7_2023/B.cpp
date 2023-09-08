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

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        pair<ll, ll> a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].first -= k;
            a[i].second = i;
        }
        vector<ll> s, t;
        stable_sort(a, a + n, cmp);
        for (ll i = 0; i < n; i++)
        {
            if (a[i].first <= 0)
                s.push_back(a[i].second + 1);
            else
                t.push_back(a[i].second + 1);
        }
        for (auto x : s)
            cout << x << " ";
        for (auto x : t)
            cout << x << " ";
        cout << endl;
    }
}