#include <bits/stdc++.h>
using namespace std;

int n, a[100][100], visited[100][100];
vector<string> ans;
const int x[4] = {1, 0, 0, -1};
const int y[4] = {0, 1, -1, 0};
const string S = "DRLU";

void Try_1(int i, int j, string s)
{

    if (i == n && j == n)
    {
        ans.push_back(s);
        return;
    }
    for (int k = 0; k < 4; ++k)
    {
        int newx = i + x[k];
        int newy = j + y[k];
        if (newx >= 1 && newx <= n && newy >= 1 && newy <= n && a[newx][newy] && !visited[newx][newy])
        {
            // s+=S[k];
            visited[newx][newy] = 1;
            Try_1(newx, newy, s + S[k]);
            visited[newx][newy] = 0;
        }
    }
}

void solve()
{
    cin >> n;
    memset(visited, 0, sizeof(visited));
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == 0 || a[n][n] == 0)
    {
        cout << -1 << endl;
        return;
    }
    ans.clear();
    visited[1][1] = 1;
    Try_1(1, 1, "");
    if (ans.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}

// 3
// 4
// 1 0 0 0
// 1 1 0 1
// 0 1 0 0
// 0 1 1 1
// 4
// 1 0 0 0
// 1 1 0 1
// 1 1 0 0
// 0 1 1 1
// 5
// 1 0 0 0 0
// 1 1 1 1 1
// 1 1 1 0 1
// 0 0 0 0 1
// 0 0 0 0 1