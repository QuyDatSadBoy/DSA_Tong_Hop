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

int main()
{
    faster();
    ll n;
    cin >> n;
    ll a[n];
    for (auto &x : a)
        cin >> x;
    map<ll, ll> mp;
    mp[0] = 1;
    // kỹ thuật cần nhớ nếu a%k=b%k thì abs(a-b)%k=0
    ll ans = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        ans += mp[((sum % n) + n) % n];
        mp[((sum % n) + n) % n]++;
    }
    cout << ans << endl;
}