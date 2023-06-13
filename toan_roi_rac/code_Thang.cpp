void dijstra(int u)
{
    d[u] = 0;
    for (int i = 1; i <= n; i++)
    {
        d[i] = a[u][i];
        truoc[i] = u;
        codinh[i] = false;
    }
    codinh[u] = true;
    int t = n - 1;
    while (t--)
    {
        int mi = 1e9;
        int u;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] < mi && !codinh[i])
            {
                u = i;
                mi = d[i];
            }
        }
        codinh[u] = true;
        for (int v = 1; v <= n; v++)
        {
            if (codinh[v] && d[v] > d[u] + a[u][v])
            {
                d[v] = d[u] + a[u][v];
                truoc[v] = u;
            }
        }
    }
}