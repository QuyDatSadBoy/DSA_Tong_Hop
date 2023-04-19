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
ll n, a[1001][1001], visited[1000001];
void init()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}
bool check(ll v)
{
    for (ll i = 1; i <= n; i++)
    {
        if (a[v][i])
        {
            return true;
        }
    }
    return false;
}

void euler(ll s)
{
    stack<ll> st;
    vector<ll> Ec;
    st.push(s);
    while (!st.empty())
    {
        ll top = st.top();
        if (check(top))
        {
            for (ll i = 1; i <= n; i++)
            {
                if (a[top][i])
                {
                    st.push(i);
                    a[top][i] = 0;
                    break;
                }
            }
        }
        else
        {
            Ec.push_back(top);
            st.pop();
        }
    }
    reverse(all(Ec));
    for (ll x : Ec)
        cout << x << " ";
    cout << endl;
}
int main()
{
    faster();
    init();
    euler(1);
}