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

int main()
{
    faster();
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;
    int f1[n] = {0};
    int f2[n] = {0};
    for (int i = 0; i < n; i++)
    {
        f1[i] = a[i];
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                f1[i] = max(f1[i], f1[j] + a[i]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        f2[i] = a[i];
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j])
            {
                f2[i] = max(f2[i], f2[j] + a[i]);
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, f1[i] + f2[i] - a[i]);
    }
    cout << ans << endl;
}