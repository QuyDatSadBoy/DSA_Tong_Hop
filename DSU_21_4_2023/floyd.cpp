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
    int n, m;
    cin >> n >> m;
    int d[n + 5][n + 5];
    // Goi d[i][j] la khoang cach be nhat giua i va j
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            d[i][j] = 1e9;
        d[i][i] = 0;
    }

    while (m--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        d[x][y] = d[y][x] = w;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << d[x][y] << endl;
    }
}