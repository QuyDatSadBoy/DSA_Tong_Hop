#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
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
    node(ll x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void makeRoot(node *&root, ll u, ll v, char c)
{
    if (c == 'L')
        root->left = new node(v);
    else
        root->right = new node(v);
}
void insertNode(node *&root, ll u, ll v, char c)
{
    if (root == NULL)
        return;
    if (root->data == u)
    {
        makeRoot(root, u, v, c);
    }
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

bool check(node *root, node *root2)
{
    if (root == NULL && root2 == NULL)
        return true;
    else
    {
        if (root != NULL && root2 != NULL)
        {
            return root->data == root2->data && check(root->left, root2->left) && check(root->right, root2->right);
        }
        else
            return false;
    }
}
int main()
{
    faster();
    node *root = NULL;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll u, v;
        char c;
        cin >> u >> v >> c;
        if (root == NULL)
        {
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else
            insertNode(root, u, v, c);
    }
    node *root2 = NULL;
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        char c;
        cin >> u >> v >> c;
        if (root2 == NULL)
        {
            root2 = new node(u);
            makeRoot(root2, u, v, c);
        }
        else
            insertNode(root2, u, v, c);
    }
    if (check(root, root2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}