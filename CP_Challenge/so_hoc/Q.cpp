#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn
using namespace std;
int t, n;
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector <int> a;
        for (int i=2; i<=sqrt(n); ++i) if (n % i == 0)
        {
            a.push_back(i);
            if (i * i != n) a.push_back(n/i);
        }
        a.push_back(n);
        sort(a.begin(), a.end());
        int tmp = n;
        vector <int> p;
        for (int i=2; i<=sqrt(tmp); ++i)
            if (tmp % i == 0)
        {
            p.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }
        if (tmp > 1) p.push_back(tmp);
        map <int, bool> used;
        vector <int> ans;
        if (p.size() == 2)
        {
            if (p[0] * p[1] == n)
            {
                cout << p[0] << ' ' << p[1] << ' ' << n; el;
                cout << 1; el;
            }
            else
            {
                used[p[0]] = 1;
                used[p[1]] = 1;
                used[p[0] * p[1]] = 1;
                used[n] = 1;
                ans.push_back(p[0]);
                for (int x:a) if (used[x] == 0 && x % p[0] == 0) ans.push_back(x), used[x] = 1;
                ans.push_back(p[0] * p[1]);
                ans.push_back(p[1]);
                for (int x:a) if (used[x] == 0 && x % p[1] == 0) ans.push_back(x), used[x] = 1;
                ans.push_back(n);
                for (auto x:ans) cout << x << ' '; el;
                cout << 0; el;
            }
        }
        else
        {
            for (int i=0; i<p.size(); ++i)
            {
                used[p[i]] = 1;
                used[p[i] * p[(i+1)%(int)(p.size())]] = 1;
            }
            for (int i=0; i<p.size(); ++i)
            {
                ans.push_back(p[i]);
                for (auto x:a)
                    if (used[x] == 0 && x % p[i] == 0) ans.push_back(x), used[x] = 1;
                ans.push_back(p[i] * p[(i+1)%(int)(p.size())]);
            }
            for (auto x:ans) cout << x << ' '; el;
            cout << 0; el;
        }
    }
}