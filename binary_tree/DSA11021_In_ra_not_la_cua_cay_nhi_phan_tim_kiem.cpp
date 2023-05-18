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
void print_leave(node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";
    else
    {
        print_leave(root->left);
        print_leave(root->right);
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
        print_leave(root);
        cout << endl;
        root = NULL;
        delete root;
    }
}