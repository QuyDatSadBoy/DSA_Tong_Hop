#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
bool check(ll a[], int n, int k, ll sum)
{
	int cnt = 0;
	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		res += a[i];
		if (res > sum)
		{
			res = a[i];
			++cnt;
		}
	}
	++cnt;
	return cnt <= k;
}
int main()
{
	int n, k;
	cin >> n >> k;
	ll a[n], Max = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		Max = max(a[i], Max);
	}
	ll l = Max, res, r = sum;
	while (l <= r)
	{
		ll m = (l + r) / 2;
		if (check(a, n, k, m))
		{
			res = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	cout << res;
}
