// Check Cycle Using DFS
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int parent[100005];
int visited[100005];
int ans = 0;

void DFS(int u)
{
    stack<int> st;
    st.push(u);
    visited[u] = 1;
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        bool flag = false;
        for (auto &y : adj[x])
        {
            if (!visited[y])
            {
                parent[y] = x;
                visited[y] = 1;
                st.push(x);
                st.push(y);
                break;
                flag = true;
            }
            else if (y != parent[x] && x != parent[y])
            {
                ans = 1;
            }
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS(i);
    }
    cout << ans;
    return 0;
}