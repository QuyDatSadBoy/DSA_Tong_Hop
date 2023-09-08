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
// Đếm số mảng con có tổng bằng x các phần tử liên tiếp

int main()
{
    // Đếm số mảng con liên tiếp có tổng = x có thể có phần tử âm
    faster();
    ll n, x;
    cin >> n >> x;
    ll a[n];
    for (auto &x : a)
        cin >> x;
    map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0, sum = 0; // lưu kết quả
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        if (mp[sum - x])
            ans += mp[sum - x];
        mp[sum]++;
    }
    cout << ans << endl;
}