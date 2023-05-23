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

int n, k;
int a[30];
vector<string> temp;
vector<vector<string>> res;

void solve()
{
    vector<string> x;
    for (int i = 1; i <= k; ++i)
    {
        x.push_back(temp[a[i]]);
    }
    sort(x.begin(), x.end());
    res.push_back(x);
}

void Try(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; ++j)
    {
        a[i] = j;
        if (i == k)
            solve();
        else
            Try(i + 1);
    }
}

void testCase()
{
    cin >> n >> k;
    set<string> se;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        se.insert(s);
    }
    temp.push_back("");
    for (auto i : se)
    {
        temp.push_back(i);
    }
    n = se.size();
    Try(1);
    sort(res.begin(), res.end());
    for (auto i : res)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    faster();
    int T = 1;
    while (T--)
    {
        testCase();
        cout << "\n";
    }
    return 0;
}