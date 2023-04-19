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

int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        ll f[256] = {0}; // luu lai dau ngoac co thua hay khong
        stack<pair<ll, ll>> st;
        // luu vi tri va muc do quan trong
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[0] == '(')
            {
                st.push({i, -1}); // -1 la ngoac thua
            }
            else
            {
                if (s[i] == ' ')
                    continue;
                else
                {
                                }
            }
        }
    }
}