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
ll res = 1;
bool isleave(node *root)
{
    if (root == NULL)
        return false;
    else
    {
        if (root->left == NULL && root->right == NULL)
            return true;
        else
            return false;
    }
}
void cnt_parent(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root->left)
        {
            if (!isleave(root->left))
                res++;
            cnt_parent(root->left);
        }
        if (root->right)
        {
            if (!isleave(root->right))
                res++;
            cnt_parent(root->right);
        }
    }
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
        ll u;
        while (n--)
        {
            cin >> u;
            root = insert_node(root, u);
        }
        cnt_parent(root);
        cout << res << endl;
        res = 1;
        root = NULL;
        delete root;
    }
}