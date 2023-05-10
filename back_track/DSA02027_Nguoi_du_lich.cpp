#include <stdio.h>
#include <string.h>
#pragma GCC optimize("Ofast")
#define bit(x, i) ((x >> i) & 1)
inline int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    int n;
    scanf("%d", &n);
    int c[n][n], f[n][1 << n], ans = 1e9;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            scanf("%d", &c[i][j]);
    }
    memset(f, 64, sizeof(f));
    f[0][1 << 0] = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            if (bit(x, i) == 1)
            {
                int pre = x - (1 << i);
                for (int j = 0; j < n; ++j)
                {
                    if (bit(pre, j) == 1)
                    {
                        f[i][x] = min(f[i][x], f[j][pre] + c[i][j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans = min(ans, f[i][(1 << n) - 1] + c[i][0]);
    }
    printf("%d\n", ans);
}