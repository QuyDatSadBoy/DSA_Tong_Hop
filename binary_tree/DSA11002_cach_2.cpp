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
struct node
{
    string data;
    node *left, *right;
    node(string s)
    {
        data = s;
        left = right = NULL;
    }
};
string a[1001];
ll n;
node *buildTree(node *root, ll i)
{
    if (i < n)
    {
        root = new node(a[i]);
        root->left = buildTree(root->left, i * 2 + 1);
        root->right = buildTree(root->right, i * 2 + 2);
    }
    return root;
}
ll calc(node *root)
{
    if (root->data != "+" && root->data != "-" && root->data != "*" && root->data != "/")
    {
        return stoll(root->data);
    }
    else
    {
        if (root->data == "+")
            return calc(root->left) + calc(root->right);
        else if (root->data == "-")
            return calc(root->left) - calc(root->right);
        else if (root->data == "*")
            return calc(root->left) * calc(root->right);
        else if (root->data == "/")
            return calc(root->left) / calc(root->right);
        else
            return 0;
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin.ignore(1);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        node *root = NULL;
        root = buildTree(root, 0);
        cout << calc(root) << endl;
        root = NULL;
        delete root;
    }
}