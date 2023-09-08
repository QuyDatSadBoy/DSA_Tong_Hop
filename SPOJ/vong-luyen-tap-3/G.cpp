#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, t;
    cin >> n >> t;
    bool check[t + 1] = {false};
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b) -> bool
         {
        if(a.first != b.first) return a.first >b.first;
        else return a.second < b.second; });
    ll time = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        if (time >= t)
            break;
        bool ok = false;
        for (ll j = v[i].second; j >= 0; j--)
        {
            if (!check[j])
            {
                ok = true;
                check[j] = true;
                time++;
                break;
            }
        }
        if (ok)
            sum += v[i].first;
    }
    cout << sum;
    return 0;
}