#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

string str;
char Operator[2] = {'+', '-'};
bool oke;

bool isCorrect()
{
    ll x = stoi(str.substr(0, 2));
    ll y = stoi(str.substr(5, 2));
    ll z = stoi(str.substr(10, 2));
    if (x < 10 || y < 10 || z < 10)
    {
        return false;
    }
    if (str[3] == '+')
        return (x + y == z);
    else
        return (x - y == z);
}

void Back_track(int i)
{
    if (oke)
        return;
    if (i == str.length())
    {
        if (isCorrect())
        {
            oke = 1;
            cout << str;
        }
        return;
    }
    if (str[i] == '?')
    {
        if (i == 3)
        {
            for (int j = 0; j <= 1; ++j)
            {
                str[i] = Operator[j];
                Back_track(i + 1);
                str[i] = '?';
            }
        }
        else
        {
            for (int j = 0; j <= 9; ++j)
            {
                str[i] = j + '0';
                Back_track(i + 1);
                str[i] = '?';
            }
        }
    }
    else
    {
        Back_track(i + 1);
    }
}

void solve()
{
    oke = false;
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '*' or str[i] == '/')
        {
            cout << "WRONG PROBLEM!";
            return;
        }
    }
    Back_track(0);
    if (!oke)
    {
        cout << "WRONG PROBLEM!";
    }
}

int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}