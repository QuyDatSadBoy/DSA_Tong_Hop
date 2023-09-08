#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1000005;

ll n, q, a[maxn], bit[maxn], type, u, v, k;
;

void update(ll x, ll value)
{
    while (x <= n)
    {
        bit[x] += value;
        x += (x & (-x));
    }
}

void range_update(ll u, ll v, ll k)
{
    update(u, k);
    update(v + 1, -k);
}

ll get(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += bit[x];
        x -= (x & (-x));
    }
    return ans;
}

void init()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
        update(i + 1, -a[i]);
    }
    cin >> q;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> u >> v >> k;
            range_update(u, v, k);
        }
        else
        {
            cin >> u;
            cout << get(u) << endl;
        }
    }

    return 0;
}
