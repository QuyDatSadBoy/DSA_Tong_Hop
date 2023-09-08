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

ll m;
ll subarrays(vector<ll> arr, ll n, ll s, ll k)
{
    vector<vector<ll>> dp(s + 1, vector<ll>(k + 1, 0)); // mảng dp lưu lại số mảng con có tổng S có k phần tử
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = s; j >= 1; j--) // cho s ra ngoài để 1 tập con không bị lấy lại 2 lần ví dụ mảng 7 7 thì số mảng con độ dài 2 tổng 14 chỉ là 1
        {
            for (ll l = 1; l <= k; l++)
            {
                if (j >= arr[i - 1])
                {
                    dp[j][l] += dp[j - arr[i - 1]][l - 1];
                    dp[j][l] %= mod;
                }
            }
        }
    }
    // Ta đã có 1 mảng con full có tổng s và k phần tử
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= s; j++)
        {
            if ((j % i == 0) && (j / i == m))
            {
                cnt += dp[j][i];
                cnt %= mod;
            }
        }
    }
    return cnt;
}

int main()
{
    faster();
    ll T;
    cin >> T;
    for (ll t = 0; t < T; t++)
    {
        ll n;
        cin >> n >> m;
        ll sum = 0, k = n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        ll result = subarrays(arr, n, sum, k);
        cout << result << endl;
    }

    return 0;
}