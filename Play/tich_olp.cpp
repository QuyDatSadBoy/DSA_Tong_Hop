#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) ((x>>i)&1)
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
void solve()
{
    ll P;
    cin >> P;
    if (P == 1 || P == 0) { 
        cout << P;
    } else {
        stack<int>st;
        for (int i = 9; i >= 2; i--) {
            if (P % i == 0) {
                while (P % i == 0) {
                    st.push(i);
                    P /= i;
                }
            }
        }
         if (P != 1) cout << -1;
        else {
            while (!st.empty()) {
                 cout << st.top();
                st.pop();
             }
        } 
    }
    cout << endl;
}


int main()
{
    faster();
    ll t; cin>>t;
    while(t--)
    {
      solve();
    }

}