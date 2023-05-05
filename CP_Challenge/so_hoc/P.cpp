#include <bits/stdc++.h>
#define el cout << "\n"
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define maxn 200005
#define MOD 1000000007
using namespace std;
int n, q, a[maxn];
multiset<int> s[maxn];
int d[maxn];
map<int, int> m[maxn];
long long ans = 1;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    f1(i, n) cin >> a[i];
    for (int i = 2; i * i < maxn; ++i)
        if (d[i] == 0)
            for (int j = i * i; j < maxn; j += i)
                if (d[j] == 0)
                    d[j] = i;
    for (int i = 2; i < maxn; ++i)
        if (d[i] == 0)
            d[i] = i;
    f1(i, n) while (a[i] > 1)
    {
        int x = d[a[i]], cnt = 0;
        while (a[i] % x == 0)
            a[i] /= x, cnt++;
        m[i][x] = cnt;
        s[x].insert(cnt);
    }
    f1(i, maxn - 1)
    {
        if (s[i].size() == n)
            for (int j = 1; j <= *s[i].begin(); j++)
                (ans *= i) %= MOD;
    }
    while (q--)
    {
        int i, val;
        cin >> i >> val;
        while (val > 1)
        {
            int x = d[val], cnt = 0;
            while (val % x == 0)
                val /= x, cnt++;
            int pre = (s[x].size() == n ? *s[x].begin() : 0);
            if (m[i][x])
                s[x].erase(s[x].find(m[i][x]));
            m[i][x] += cnt;
            s[x].insert(m[i][x]);
            int nxt = *s[x].begin();
            if (s[x].size() == n)
            {
                for (int j = pre + 1; j <= nxt; ++j)
                    (ans *= x) %= MOD;
            }
        }
        cout << ans;
        el;
    }
}