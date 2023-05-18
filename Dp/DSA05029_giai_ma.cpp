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
void solve(string s)
{
    // Đạt trùm copy paste
    ll n = s.size();
    ll f[n + 1] = {0};
    s = "@" + s;
    if (s[1] == '0') // chữ A mã hóa là 1 nên bắt đầu từ 0 ko thể giải mã
    {
        cout << 0 << endl;
        return;
    }
    f[0] = f[1] = 1; // gán f[0]=1 là để cho trường hợp ví dụ 12 có 2 cách giải mã AB hoặc là ký tự ở vị trí số 12 cộng vào mới đủ
    for (ll i = 2; i <= n; i++)
    {
        if (s[i] == '0') // không phải ký tự đầu tiên mà bằng 0 nếu trước nó không phải là các số 1,2 thì số này sẽ vượt quá 26 sai
        {
            if (s[i - 1] != '1' && s[i - 1] != '2')
            {
                cout << 0 << endl;
                return;
            }
            f[i] = f[i - 2]; // số 0 bắt buộc phải ghép với ký tự s[i-1] nên số cách của nó sẽ bằng số cách để mã hóa i-2 ký tự
        }
        else
        {
            f[i] = f[i - 1]; // khác 0 thì ít nhất sẽ có f[i-1] cách r
            // nếu ký tự s[i] và s[i-1] có thể tạo thành 1 từ riêng thì sẽ cộng thêm số cách để tạo thành f[i-2]
            // ví dụ : 112 có 12 có thể tạo thành 1 ký tự riêng nên cộng thêm f[i-2]
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) // kiểm tra s[i] và s[i-1] có thuộc từ 1 đến 26 hay không
            {
                f[i] += f[i - 2];
            }
        }
    }
    cout << f[n] << endl;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
}