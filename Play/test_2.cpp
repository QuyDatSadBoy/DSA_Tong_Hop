#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int i = 1, res = 0, j = i + 1;
        while (i < n - 1)
        {
            if (a[i - 1] + a[i] + a[j] < k && j < n)
            {
                res++;
                cout << "i-1=" << i - 1 << " i=" << i << " j=" << j << endl;
                cout << a[i - 1] << " " << a[i] << " " << a[j] << endl;
                j++;
            }
            else
            {
                i++;
                j = i + 1;
            }
        }
        cout << res << endl;
    }
}