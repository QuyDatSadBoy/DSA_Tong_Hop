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

// trò chơi cắt dây có n đoạn dây bạn cần cắt k đoạn dây có cùng chiều dài từ chúng
ll n, k, a[1000001];
bool check(double mid)
{
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        res += (a[i] * 1.0 / mid);
    }
    return res >= k;
}
int main()
{
    faster();
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    double l = 0, r = 1e18;
    for (ll i = 1; i <= 120; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
            r = mid;
    }
    cout << fixed << setprecision(6) << l << endl;
}