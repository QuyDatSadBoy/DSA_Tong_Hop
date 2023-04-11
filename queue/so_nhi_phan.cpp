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
vector<ll> res;
ll a[201];
int main()
{
    faster();
    queue<ll> qe;
    qe.push(8);
    while (!qe.empty())
    {
        ll top = qe.front();
        qe.pop();
        if (top > (ll)(1e18))
            break;
        res.push_back(top);
        qe.push(top * 10);
        qe.push(top * 10 + 8);
    }
    for (ll i = 1; i <= 200; i++)
    {
        for (auto x : res)
        {
            if (x % i == 0)
            {
                a[i] = x;
                break;
            }
        }
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}