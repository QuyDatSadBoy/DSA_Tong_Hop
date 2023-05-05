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

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        int check = 1;
        for (int i = n; i >= 0; i--)
        {
            int dem = 0;
            for (int j = 0; j <= i; j++)
                dem += mp[j];
            if (n - mp[i] == i)
            {
                if (i <= n - dem && dem != 0)
                {
                    cout << i << endl;
                    check = 0;
                    break;
                }
            }
            else
            {
                int dem2 = 0;
                for (int k = i + 1; k <= n; k++)
                    if (mp[k] != 0 && k <= n - dem)
                        dem2 = 1;
                if (i <= n - dem && dem != 0 && !dem2)
                {
                    cout << i << endl;
                    check = 0;
                    break;
                }
            }
        }
        if (check)
            cout << "-1" << endl;
    }
}