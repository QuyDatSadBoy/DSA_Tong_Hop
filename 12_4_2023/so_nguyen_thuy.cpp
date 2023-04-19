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
vector<string> res;
bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}
void init()
{
    queue<string> qe;
    ll cnt = 0;
    qe.push("4");
    qe.push("5");
    while (1)
    {
        string top = qe.front();
        qe.pop();
        res.push_back(top);
        string tam = top;
        reverse(all(tam));
        res.push_back(top + tam);
        if (res.size() > (int)(3))
            break;
    }
    sort(all(res), cmp);
}
int main()
{
    faster();
    init();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}