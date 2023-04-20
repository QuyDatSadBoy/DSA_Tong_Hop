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
ll cnt = 0;
ll dfs(ll n)
{
    if (n == 4)
        return 100;
    if (n > 1)
    {
        dfs(n + 1);
        if (n == 3)
            return 1;
    }
    return 10;
}
int main()
{
    faster();
    cout << dfs(2) << endl;
}