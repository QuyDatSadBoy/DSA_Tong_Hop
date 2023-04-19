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
ll n, x[1000001];
void back_track(ll i, ll begin, ll sum)
{
    for (ll j = begin; j >= 1; j--)
    {
        if (sum + j <= n)
        {
            x[i] = j;
            if (sum + j == n)
            {
                for (ll k = 1; k <= i; k++)
                {
                    cout << x[k];
                    if (k != i)
                        cout << " ";
                }
                cout << endl;
            }
            else
                back_track(i + 1, j, sum + j);
        }
    }
}
int main()
{
    faster();
    cin >> n;
    back_track(1, n, 0);
}