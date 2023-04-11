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
ll n, a[1000001], x[1000001];
vector<string> res;
void back_track(ll i, ll begin)
{
    if (i > 2)
    {
        string ans = "";
        for (ll j = 1; j < i; j++)
        {
            ans += to_string(x[j]) + " ";
        }
        res.push_back(ans);
    }
    for (ll j = begin; j <= n; j++)
    {
        if (a[j] > x[i - 1])
        {
            x[i] = a[j];
            back_track(i + 1, j + 1);
        }
    }
}
int main()
{
    faster();
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    back_track(1, 1);
    sort(all(res));
    for (auto x : res)
    {
        cout << x << endl;
    }
}