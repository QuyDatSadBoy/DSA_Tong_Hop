#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int bit[1000005], n, q, t, u, v, k;

int getSum(int p)
{
    int idx = p, ans = 0;
    while (idx > 0)
    {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int u, int v)
{
    int idx = u;
    while (idx <= n)
    {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r", stdin);
    // 	freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, x);
        update(i + 1, -x);
    }
    cin >> q;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> u >> v >> k;
            update(u, k);
            update(v + 1, -k);
        }
        else
        {
            cin >> k;
            cout << getSum(k) << endl;
        }
    }
    return 0;
}