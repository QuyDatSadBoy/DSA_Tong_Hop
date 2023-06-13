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
ll parent[100001], size[100001], n;
void init()
{
    for (ll i = 1; i <= 100000; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}
ll find(ll a)
{
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);
}
bool Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (size[a] < size[b])
    {
        parent[a] = b;
        size[b] += size[a];
    }
    else
    {
        size[a] += size[b];
        parent[b] = a;
    }
    return true;
}
int main()
{
    faster();
    init();
    cin >> n;
    while (n--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        if (z == 1)
        {
            Union(x, y);
        }
        else
        {
            if (find(x) == find(y))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
}