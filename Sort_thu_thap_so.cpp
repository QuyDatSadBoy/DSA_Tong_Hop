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
// Đếm số lần thu thập số tối thiểu
int main()
{
    faster();
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[x] = i;
    }
    ll cnt = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] < a[i - 1])
            cnt++;
    }
    cout << cnt << endl;
    // Tức là các số input chỉ nằm trong từ 1 -> n
    // Mảng a lưu vị trí các số xuất hiện ta luôn cần ít nhất 1 vòng lặp nên khởi tạo biến cnt=1
    // đếm từ số 2 nếu thấy số to hơn xuất hiện sau số bé hơn thì tăng cnt lên
}