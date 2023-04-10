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
ll n, a[1001][1001], visited[1001][1001], ok = 0;
void back_track(ll i, ll j, string s)
{
    if (i == n && j == n)
    {
        ok = 1;
        cout << s << endl;
        return;
    }
    if (i >= 1 && i + 1 <= n && a[i + 1][j] == 1 && visited[i + 1][j] == 0)
    {
        visited[i + 1][j] = 1;
        back_track(i + 1, j, s + "D");
        visited[i + 1][j] = 0;
    }
    if (j >= 1 && j + 1 <= n && a[i][j + 1] == 1 && visited[i][j + 1] == 0)
    {
        visited[i][j + 1] = 1;
        back_track(i, j + 1, s + "R");
        visited[i][j + 1] = 0;
    }
}
int main()
{
    faster();
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    back_track(1, 1, "");
    if (ok == 0)
        cout << -1 << endl;
}