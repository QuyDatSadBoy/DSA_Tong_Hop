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
int n, k, a[16];
vector<int> v;
void back_track(int i, int pos, int cnt)
{
    if (cnt >= k)
    {
        for (ll h = 1; h <= k; h++)
            cout << v[h] << " ";
        cout << endl;
        return;
    }
    if (i > n)
        return;
    for (ll j = pos; j < n; j++)
    {
        if (a[j] > v[i - 1])
        {
            v.push_back(a[j]);
            cnt++;
        }
        back_track(i + 1, j + 1, cnt);
        cnt--;
        v.pop_back();
    }
}
int main()
{
    faster();
    v.push_back(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        back_track(1, 0, 0);
    }
}