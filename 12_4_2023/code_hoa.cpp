#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];

void DFS(int s)
{
    stack<int> st;
    st.push(s);
    visited[s] = true;
    cout << s << " ";
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        for (auto &y : adj[x])
        {
            if (!visited[y])
            {
                cout << y << " ";
                visited[y] = true;
                st.push(x);
                st.push(y);
            }
        }
    }
}
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    DFS(s);
    return 0;
}