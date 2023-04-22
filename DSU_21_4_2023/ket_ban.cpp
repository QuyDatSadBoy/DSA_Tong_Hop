#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
int n, m, ans, parent[100001], num[100001];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        num[i] = 1;
    }
}
int Find(int u)
{
    if (u != parent[u])
        parent[u] = Find(parent[u]);
    return parent[u];
}
void Union(int u, int v)
{
    int a = Find(u), b = Find(v);
    if (a == b)
        return;
    if (num[a] < num[b])
        swap(a, b);
    parent[b] = a;
    num[a] += num[b];
    ans = max(ans, num[a]);
}
main()
{
    int t, u, v;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> m;
        init();
        while (m--)
        {
            cin >> u >> v;
            Union(u, v);
        }
        cout << ans << endl;
    }
}