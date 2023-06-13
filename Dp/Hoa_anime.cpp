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
int bia_decimal(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res = res * 2 + (s[i] - '0');
    }
    return res;
}
void bi_hex(string s)
{
    string res = "", tam = "";
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (cnt < 4)
        {
            tam = s[i] + tam;
            cnt++;
        }
        else
        {
            if (cnt == 4)
            {
                int dem = bia_decimal(tam) % 16;
                char c;
                if (dem < 10)
                    c = dem + '0';
                else
                {
                    c = 'A' + (dem - 10);
                }
                res = c + res;
                tam = "";
                tam += s[i];
                cnt = 1;
            }
        }
    }
    if (tam.size())
    {
        int dem = bia_decimal(tam) % 16;
        char c;
        if (dem < 10)
            c = dem + '0';
        else
        {
            c = 'A' + (dem - 10);
        }
        res = c + res;
    }
    cout << res << endl;
}
int n;
char a[1001][1001];
string dp[1001][1001];
int main()
{
    faster();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            dp[i][j] = "";
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                dp[i][j] += a[i][j];
            }
            else
            {
                if (i == 1)
                {
                    dp[i][j] = dp[i][j - 1] + a[i][j];
                }
                else
                {
                    if (j == 1)
                        dp[i][j] = dp[i - 1][j] + a[i][j];
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]);
                    }
                }
            }
        }
    }
    bi_hex(dp[n][n]);
}