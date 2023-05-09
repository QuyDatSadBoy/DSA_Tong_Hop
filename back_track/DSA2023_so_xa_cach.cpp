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
int n, a[12];
bool visited[11];
inline void back_track(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (visited[j] == 0)
        {
            if (abs(j - a[i - 1]) != 1)
            {
                visited[j] = 1;
                a[i] = j;
                if (i == n)
                {
                    for (ll k = 1; k <= n; k++)
                        cout << a[k];
                    cout << endl;
                }
                else
                    back_track(i + 1);
                visited[j] = 0;
            }
        }
    }
}
int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a[0] = 11;
        back_track(1);
        ms(visited);
    }
}