#include <bits/stdc++.h>
using namespace std;
int prime[10000005] = {0};
int va[10000005] = {0};
int kq[10000005] = {0};
set<int> se;
void sang()
{
    prime[1] = 1;
    for (int i = 2; i <= sqrt(1e7 + 5); i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= 1e7 + 2; j += i)
            {
                if (prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
    for (int i = 2; i <= 1e7 + 2; i++)
        if (prime[i] == 0)
            prime[i] = i;
}
void check(int n)
{
    int res = 0, dem = 1;
    while (n != 1)
    {
        if (res == prime[n])
            dem++;
        if (res != prime[n])
        {
            kq[res] += dem;
            va[res] = max(va[res], dem);
            res = prime[n];
            se.insert(res);
            dem = 1;
        }
        n /= prime[n];
    }
    kq[res] += dem;
    va[res] = max(va[res], dem);
}
long long Pow(long long n, int x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return n;
    long long res = Pow(n, x / 2);
    if (x % 2 == 0)
        return res * res;
    else
        return res * res * n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sang();
    int n;
    cin >> n;
    bool ok = true;
    int a[n + 5];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int tmp1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            ok = false;
            break;
        }
        if (a[i] < 0)
            tmp1++;
        check(a[i]);
    }
    if (tmp1 == n)
        ok = false;
    if (!ok)
    {
        cout << "impossible";
        return 0;
    }
    long long tmp = 1;
    for (int i : se)
    {
        tmp *= Pow((long long)i, kq[i] - va[i]);
    }
    cout << tmp << endl;
}