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

vector<int> trai(vector<int> a)
{
    vector<int> b(6);
    b[0] = a[3];
    b[1] = a[0];
    b[2] = a[2];
    b[5] = a[5];
    b[3] = a[4];
    b[4] = a[1];
    return b;
}
vector<int> phai(vector<int> a)
{
    vector<int> b(6);
    b[0] = a[0];
    b[3] = a[3];
    b[1] = a[4];
    b[2] = a[1];
    b[4] = a[5];
    b[5] = a[2];
    return b;
}
bool cmp(vector<int> a, vector<int> b)
{
    for (int i = 0; i < 6; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
int BFS(vector<int> a, vector<int> b)
{
    queue<pair<vector<int>, int>> q;
    q.push({a, 0});
    while (true)
    {
        pair<vector<int>, int> top = q.front();
        q.pop();
        if (cmp(top.first, b))
            return top.second;

        q.push({trai(top.first), top.second + 1});
        q.push({phai(top.first), top.second + 1});
    }
    return -1;
}
int main()
{
    faster();
    vector<int> a(6);
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    vector<int> b(6);
    for (int i = 0; i < 6; i++)
        cin >> b[i];
    cout << BFS(a, b) << endl;
    return 0;
}