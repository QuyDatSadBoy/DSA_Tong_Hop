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

char a[4][4];
void solve()
{
    if (a[1][1] == a[1][2] && a[1][2] == a[1][3])
    {
        if (a[1][1] != '.')
        {
            cout << a[1][1] << endl;
            return;
        }
    }
    if (a[2][1] == a[2][2] && a[2][2] == a[2][3])
    {
        if (a[2][1] != '.')
        {
            cout << a[2][1] << endl;
            return;
        }
    }
    if (a[3][1] == a[3][2] && a[3][2] == a[3][3])
    {
        if (a[3][1] != '.')
        {
            cout << a[3][1] << endl;
            return;
        }
    }
    if (a[1][1] == a[2][1] && a[2][1] == a[3][1])
    {
        if (a[1][1] != '.')
        {
            cout << a[1][1] << endl;
            return;
        }
    }
    if (a[1][2] == a[2][2] && a[2][2] == a[3][2])
    {
        if (a[1][2] != '.')
        {
            cout << a[1][2] << endl;
            return;
        }
    }
    if (a[1][3] == a[2][3] && a[2][3] == a[3][3])
    {
        if (a[1][3] != '.')
        {
            cout << a[1][3] << endl;
            return;
        }
    }
    if (a[1][1] == a[2][2] && a[2][2] == a[3][3])
    {
        if (a[1][1] != '.')
        {
            cout << a[1][1] << endl;
            return;
        }
    }
    if (a[3][1] == a[2][2] && a[2][2] == a[1][3])
    {
        if (a[2][2] != '.')
        {
            cout << a[2][2] << endl;
            return;
        }
    }
    cout << "DRAW" << endl;
}

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ms(a);
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
                cin >> a[i][j];
        }
        solve();
    }
}
