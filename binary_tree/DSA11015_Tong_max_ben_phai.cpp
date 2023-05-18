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
    ll data;
    node *left, *right;
    node(ll value)
    {
        data = value;
        left = right = NULL;
    }
};
void insert_node(node *&root, ll u, ll v, char c)
{
    if (root == NULL)
    {
        root = new node(u);
        if (c == 'L')
            root->left = new node(v);
        else
            root->right = new node(v);
    }
    else
    {
        if (root->data == u)
        {
            if (c == 'L')
                root->left = new node(v);
            else
                root->right = new node(v);
            return;
        }
        else
        {
            if (root->left)
                insert_node(root->left, u, v, c);
            if (root->right)
                insert_node(root->right, u, v, c);
        }
    }
}
ll res = -1e9;
ll find_Max(node *root)
{
    if (root == NULL)
        return 0;
    ll L = find_Max(root->left);
    ll R = find_Max(root->right);
    if (root->left == NULL && root->right == NULL)
        return root->data;
    if (root->left == NULL)
        return R + root->data;
    if (root->right == NULL)
        return L + root->data;
    res = max(res, L + R + root->data);
    return max(L, R) + root->data;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll u, v;
        char c;
        node *root = NULL;
        while (n--)
        {
            cin >> u >> v >> c;
            insert_node(root, u, v, c);
        }
        find_Max(root);
        cout << res << endl;
        res = -1e9;
        root = NULL;
        delete root;
    }
}