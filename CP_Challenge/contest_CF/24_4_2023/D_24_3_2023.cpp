#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "1" << endl;
            continue;
        }
        int a[n + 1];
        long long tong = 0;
        int k1 = 1, k2 = n - 1, k;
        a[1] = n;
        a[2] = n - 1;
        for (int i = 1; i <= n; i++)
            tong += i;
        set<int> s;
        s.insert(n);
        s.insert(n - 1);
        for (int i = 3; i <= n; i++)
        {
            if (i & 1)
            {
                a[i] = n - k2 + k1;
                s.insert(a[i]);
                k1++;
            }
            else
            {
                a[i] = k2 - k1;
                s.insert(a[i]);
                k2--;
            }
        }
        if (tong % n == 0 || s.size() < n)
            cout << "-1" << endl;
        else
        {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
}