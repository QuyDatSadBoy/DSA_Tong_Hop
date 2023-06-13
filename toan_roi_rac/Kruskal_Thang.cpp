Tiến Thắng using pa = pair<pair<int, int>, int>;
using vpa = vector<pair<pair<int, int>, int>>;
bool cmp(vi a, vi b)
{
    return a.second < b.second;
}
int find(int i)
{
    int tro = i;
    while (father[tro] > 0)
        tro = father[tro];
    return tro;
}
void union(int i, int j)
{
    int x = father[i] + father[j];
    if (father[i] > father[j])
    {
        father[i] = j;
        father[j] = x;
    }
    else
    {
        father[j] = i;
        father[i] = x;
    }
}
void krukal()
{
    int mi = 0;
    int i, canh = 0, dinh = 0, u, c, f1, f2, w;
    for (int i = 1; i <= n; i++)
        father[i] = -1;
    vpa e;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i][j] != 1e9)
                e.push_back({{i, j}, a[i][j]});
        }
    }
    sort(e.begin(), e.end(), cmp);
    while (dinh < n - 1 && canh < e.size())
    {
        u = e[canh].first.first;
        v = e[canh].first.second;
        w = e[canh].second;
        canh++;
        f1 = find(u);
        f2 = find(v);
        if (f1 != f2)
        {
            dinh++;
            Union(f1, f2);
            kq.push_back({u, v});
            mi += w;
        }
    }
    if (dinh != n - 1)
        cout << "Do thi khong lien thong";
    else
    {
        for (int i = 0; i < kq.size(); i++)
            cout << kq[i].first << " " << kq[i].second << endl;
        cout << mi << endl;
    }
}