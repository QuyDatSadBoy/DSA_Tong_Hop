#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
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
    // tim bit thu i
    ll x = 100;
    for (ll i = 31; i >= 0; i--)
    {
        cout << ((x >> i) & 1);
    }
    cout << endl;
    cout << __builtin_popcount(43) << endl;   // so bit 1 nhung la kieu int
    cout << __builtin_popcountll(43) << endl; // so bit 1 nhung la kieu long long
    cout << __builtin_ctzll(x) << endl;       // dem doan max bang 0 tu cuoi ve
    cout << __builtin_clz(x) << endl;         // dem doan max bang 0 tu trai qua
    bitset<30> b;                             // kich thuoc la hang so
    b[0] = 1;                                 // truy cap vao bit thu i tu phai sang
    cout << b << endl;
    cout << b.count() << endl; // so luong bit 1
    cout << b.size() << endl;  // kich thuoc
    string s = b.to_string();
    cout << s << endl;
    bitset<30> c("1001");
    cout << "c=" << c << endl;
    cout << bitset<10>(x) << endl;

    for (ll i = 5; ~i; i--)
        cout << i << " ";
    cout << endl;
    cout << c.to_ullong() << endl;

    // bat bit mask |= (1<<i)
    // tat bit i mask &=~(1<<i)
    // mask ^=(1<<i) dao trang thai
}