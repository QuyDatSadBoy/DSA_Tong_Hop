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
#define faster()                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
using namespace std;

int main()
{
  faster();
  int t = 1, n;
  cin >> t;
  while (t--)
  {
    int ans = -1;
    cin >> n;
    vi a(n);
    for (int &i : a)
      cin >> i;
    --n;
    for (int i = 0; i < n; ++i)
      if (a[i] > a[i + 1])
        ans = i + 1;
    if (ans == -1)
    {
      if (a[0] <= a[n - 1])
        cout << 0 << endl;
      else
        cout << n << endl;
    }
    else
      cout << ans << endl;
  }
  return 0;
}