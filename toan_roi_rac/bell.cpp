void bellman(int s)
{
    int d[1001];
    for (int v = 1; v <= n; v++)
    {
        d[v] = a[s][v];
        truoc[v] = s;
    }
    d[s] = 0;
    int k = n - 2;
    while (k--)
    {
        for (int v = 1; v <= n && v != s; v++)
        {
            for (int u = 1; u <= n; u++)
            {
                if (d[v] > d[u] + a[u][v])
                {
                    d[v] = d[u] + a[u][v];
                    truoc[v] = u;
                }
            }
        }
    }
}