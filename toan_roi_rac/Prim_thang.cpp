void prim(int s)
{
    vector<pair<int, int>> T;
    vector<int> vt;
    vt.push(s);
    int dT = 0;
    while (t.size() < n - 1)
    {
        int mi = 1e9, u = -1, v;
        for (int i = 0; i < vt.size(); i++)
        {
            for (int z = 1; z <= n; z++)
            {
                bool ok = true;
                for (int j = 0; j < vt.size(); j++)
                    if (v == vt[j])
                        ok = false;
                if (ok)
                {
                    if (a[i][z] < mi)
                    {
                        mi = a[i][z];
                        u = i;
                        v = z;
                    }
                }
            }
        }
        if (u == -1)
        {
            cout << "do thi khong lien thong";
            break;
        }
        else
        {
            T.push_back({u, v});
            dT += a[u][v];
        }
    }
}