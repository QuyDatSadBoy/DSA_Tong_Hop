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
ll n, k, a[1000001], ok = 1;
void back_track(ll i)
{
    for (ll j = 1; j <= n; j++)
    {
        a[i] = j;
        if (i == k)
        {
            for (ll h = 1; h <= k; h++)
            {
                cout << a[h];
            }
            cout << endl;
        }
        else
            back_track(i + 1);
    }
}
int main()
{
    faster();
    cin >> n >> k;
    back_track(1);
}