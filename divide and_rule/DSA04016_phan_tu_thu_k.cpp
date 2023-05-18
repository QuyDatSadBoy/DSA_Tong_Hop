#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define F(i, a, b) for (int i = a; i < b; ++i)
#define FD(i, a, b) for (int i = a; i > b; --i)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main()
{
    faster();
    int t = 1, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        vi a(n), b(m), res(n + m);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        merge(all(a), all(b), res.begin());
        cout << res[k - 1] << endl;
    }
    return 0;
}