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
int main()
{
    queue<ll> qe;
    qe.push(1);
    qe.push(2);
    qe.push(3);
    qe.push(4);
    qe.push(5);
    while (1)
    {
        ll top = qe.front();
        qe.pop();
        if (top > (ll)(1e5))
            break;
        res.push_back(top);
        ll mp[6] = {0};
        ll tam = top;
        while (tam)
        {
            ll r = tam % 10;
            mp[r] = 1;
            tam /= 10;
        }
        for (ll i = 0; i <= 5; i++)
        {
            if (mp[i] == 0)
            {
                qe.push(top * 10 + i);
            }
        }
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        ll cnt = 0;
        for (ll i = 0; i < res.size(); i++)
        {
            if (res[i] > r)
                break;
            if (res[i] >= l && res[i] <= r)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}