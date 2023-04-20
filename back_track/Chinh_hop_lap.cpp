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
ll n, k;
void back_track(ll i, string s)
{
    for (ll j = 1; j <= n; j++)
    {
        s += to_string(j);
        if (i == k)
        {
            cout << s << endl;
        }
        else
            back_track(i + 1, s);
        s.pop_back();
    }
}
int main()
{
    faster();
    cin >> n >> k;
    back_track(1, "");
}