#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

const int maxn = 1000001;
ll BIT[maxn], n;

void update(ll i, ll val)
{
    for (; i <= maxn; i += (i & -i))
    {
        BIT[i] += val;
    }
}

ll query(ll i)
{
    ll sum = 0;
    for (; i > 0; i -= (i & -i))
    {
        sum += BIT[i];
    }
    return sum;
}

void Convert(ll arr[], ll n)
{
    ll temp[n];
    for (ll i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
    sort(temp, temp + n);

    for (ll i = 0; i < n; i++)
    {
        arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
    }
}

ll getCount(ll arr[], ll n)
{
    Convert(arr, n);

    ll smaller_right[n + 1] = {0};
    ll greater_left[n + 1] = {0};
    for (ll i = n - 1; i >= 0; i--)
    {
        smaller_right[i] = query(arr[i] - 1);
        update(arr[i], 1);
    }

    fill_n(BIT, maxn + 1, 0);

    for (ll i = 0; i < n; i++)
    {
        greater_left[i] = i - query(arr[i]);
        update(arr[i], 1);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += greater_left[i] * smaller_right[i];
    }

    return ans;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        cout << getCount(arr, n) << endl;
        fill_n(BIT, maxn + 1, 0);
    }
    return 0;
}