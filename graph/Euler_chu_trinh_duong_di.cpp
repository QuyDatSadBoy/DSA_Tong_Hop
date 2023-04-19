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

// chu trinh euler la chu trinh di qua moi canh cua do thi dung 1 lan
// do  thi co chu trinh euler la do thi euler
// do thi co duong di euler la do thi nua euler
// do thi euler se la do thi nua  euler
ll n, m, degree[1001];
set<ll> adj[1001];
void init()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
}
void Euler(ll s)
{
    stack<ll> st;
    vector<ll> Ec;
    st.push(s);
    while (!st.empty())
    {
        ll top = st.top();
        if (adj[top].size() != 0)
        {
            ll y = *adj[top].begin();
            st.push(y);
            adj[y].erase(top);
            adj[top].erase(y);
        }
        else
        {
            Ec.push_back(top);
            st.pop();
        }
    }
    reverse(all(Ec));
    for (auto x : Ec)
        cout << x << " ";
    cout << endl;
}
int main()
{
    faster();
    init();
    Euler(4);
}