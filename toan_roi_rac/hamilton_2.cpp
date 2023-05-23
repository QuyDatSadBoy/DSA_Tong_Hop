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

vector<int> ke[21];
int visited[21] = {};
int x[21] = {}, n, v, a[21][21] = {};
ll ok = 0;
void Hal(int k)
{
    for (int i : ke[x[k - 1]])
    {
        if (k == n + 1 && i == x[1])
        {
            // for (int j = 1; j <= n; j++)
            //     cout << x[j] << " ";
            // cout << x[1] << endl;
            ok = 1;
            return;
        }
        else if (visited[i] == 0)
        {
            x[k] = i;
            visited[i] = 1;
            Hal(k + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> v;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if (a[i][j])
                    ke[i].push_back(j);
            }
        }
        x[1] = v;
        visited[v] = 1;
        Hal(2);
        if (ok)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        ms(visited);
        for (auto &x : ke)
            x.clear();
        ms(a);
        ms(x);
        ok = 0;
    }
}