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
ll n, a[1000001];
void back_track(int i, ll sum, ll begin)
{
    for (ll j = begin; j >= 1; j--)
    {
        if (sum + j <= n)
        {
            a[i] = j;
            if (sum + j == n)
            {
                for (ll k = 1; k <= i; k++)
                {
                    cout << a[k] << " ";
                }
                cout << endl;
            }
            else
                back_track(i + 1, sum + j, j);
        }
    }
}
int main()
{
    faster();
    cin >> n;
    back_track(1, 0, n);
}