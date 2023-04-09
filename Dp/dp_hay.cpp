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
// Đề bài:
// Cho số s và số t
// chọn lần lượt các số của s và t sao cho được 1 số nhỏ nhất và thứ tự các chữ số không thay đổi

int main()
{
    faster();
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    s = "@" + s;
    t = "@" + t;
    string f[n + 1][m + 1] = {""};
    f[0][0] = "";
    for (ll i = 1; i <= n; i++)
    {
        f[i][0] = f[i - 1][0] + s[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        f[0][i] = f[0][i - 1] + t[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + s[i], f[i][j - 1] + t[j]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}