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
// 2 cách làm bài in ra số lớn nhất trên 1 cửa sổ kích cỡ K
// Cách 1 : dùng Multiset
// Cách 2 : dùng deque

ll a[1000001] = {0}, n, k;
void init()
{
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void case_Multiset()
{
    multiset<ll> se;
    for (ll i = 0; i < k; i++)
    {
        se.insert(a[i]);
    }
    cout << *se.rbegin() << " ";
    for (ll i = k; i < n; i++)
    {
        se.erase(se.find(a[i - k]));
        se.insert(a[i]);
        cout << *se.rbegin() << " ";
    }
    cout << endl;
}

void case_deque()
{
    deque<ll> qe; // Phần tử qe.front() luôn là phần tử max của từng ô cửa sổ
    for (ll i = 0; i < k; i++)
    {
        if (qe.empty())
        {
            qe.push_back(i);
        }
        else
        {
            if (a[i] > a[qe.front()])
            {
                while (!qe.empty() && a[i] > a[qe.front()])
                {
                    qe.pop_front();
                }
                qe.push_front(i);
            }
            else
            {
                while (!qe.empty() && a[i] > a[qe.back()])
                {
                    qe.pop_back();
                }
                qe.push_back(i);
            }
        }
    }
    cout << a[qe.front()] << " ";
    for (ll i = k; i < n; i++)
    {
        if (qe.front() <= i - k) // kiểm tra xem phần tử max hiện tại có thuộc ô cửa sổ đang xét hay không
        {
            qe.pop_front();
        }
        if (a[i] > a[qe.front()]) // kiểm tra phần tử đang xét lớn hơn phần tử max hiện tại hay không
        {
            while (!qe.empty() && a[i] > a[qe.front()])
            {
                qe.pop_front();
            }
            qe.push_front(i);
        }
        else
        {
            while (!qe.empty() && a[i] > a[qe.back()])
            {
                qe.pop_back();
            }
            qe.push_back(i);
        }

        cout << a[qe.front()] << " ";
    }
    cout << endl;
}
int main()
{
    faster();
    init();
    case_Multiset();
    case_deque();
}