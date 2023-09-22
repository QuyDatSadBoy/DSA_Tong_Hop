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
ll Max[maxn], a[maxn];
int main()
{
	faster();
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		Max[n - 1] = a[n - 1];
		for (ll i = n - 2; i >= 0; i--)
		{
			Max[i] = max(a[i], Max[i + 1]); // số lớn nhất từ i đến cuối mảng
		}
		ll i = 0, j = 0, ans = -1;
		while (i < n && j < n)
		{
			if (Max[j] > a[i])
			{
				ans = max(ans, j - i);
				j++;
			}
			else
				i++;
		}
		cout << ans << endl;
	}
}