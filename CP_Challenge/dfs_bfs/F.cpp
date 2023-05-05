#include <bits/stdc++.h>

#define el cout << "\n"
#define file ""
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define maxn 100005

using namespace std;
int n, a[maxn], b[maxn], dd[maxn], cnt;
vector<int> ke[maxn], ans[maxn];
void dfs(int u)
{
    dd[u] = 1;
    ans[cnt].push_back(u);
    for (auto v : ke[u])
        if (!dd[v])
            dfs(v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /// freopen(file".inp","r",stdin);
    /// freopen(file".out","w",stdout);
    cin >> n;
    f1(i, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    f1(i, n)
    {
        int j = lower_bound(b + 1, b + n + 1, a[i]) - b;
        ke[i].push_back(j);
        ke[j].push_back(i);
    }
    f1(i, n) if (!dd[i])
    {
        cnt++;
        dfs(i);
    }
    cout << cnt;
    el;
    f1(i, n)
    {
        if (ans[i].size())
        {
            cout << ans[i].size() << ' ';
            for (auto x : ans[i])
                cout << x << ' ';
            el;
        }
    }
    return 0;
}