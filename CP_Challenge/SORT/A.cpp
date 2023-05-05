#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
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
    ll cnt[4] = {0}, res = 0, ans = 0;
    string s;
    cin >> s;
    for (auto x : s)
    {
        if (isdigit(x))
        {
            cnt[x - '0']++;
            res++;
        }
    }
    ans = res - 1;
    for (ll i = 1; i <= 3; i++)
    {
        if (cnt[i])
        {
            for (ll j = 1; j <= cnt[i]; j++)
            {
                cout << i;
                if (ans)
                {
                    cout << '+';
                    ans--;
                }
            }
        }
    }
}