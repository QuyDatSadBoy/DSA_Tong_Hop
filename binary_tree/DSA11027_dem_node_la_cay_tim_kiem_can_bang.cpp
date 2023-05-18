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
    node *left;
    node *right;
    node(ll value)
    {
        data = value;
        left = right = NULL;
    }
};
node *insert_node(node *root, ll u)
{
    if (root == NULL)
    {
        root = new node(u);
    }
    else
    {
        if (u < root->data)
            root->left = insert_node(root->left, u);
        else
            root->right = insert_node(root->right, u);
    }
    return root;
}
void Build_Tree(node *&root, ll a[], ll l, ll r)
{
    if (l > r)
        return;
    ll mid = (l + r) / 2;
    root = insert_node(root, a[mid]);
    Build_Tree(root, a, l, mid - 1);
    Build_Tree(root, a, mid + 1, r);
}
ll cnt_leave(node *root)
{
    ll res = 0;
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        res++;
    res += cnt_leave(root->left);
    res += cnt_leave(root->right);
    return res;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        node *root = NULL;
        ll n;
        cin >> n;
        ll a[n];
        for (auto &x : a)
            cin >> x;
        sort(a, a + n);
        Build_Tree(root, a, 0, n - 1);
        cout << cnt_leave(root) << endl;
        root = NULL;
        delete root;
    }
}