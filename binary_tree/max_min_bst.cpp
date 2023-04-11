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
node *insertNode(node *&root, ll x)
{
    if (root == NULL)
    {
        root = new node(x);
    }
    else
    {
        if (x < root->data)
        {
            root->left = insertNode(root->left, x);
        }
        else
            root->right = insertNode(root->right, x);
    }
    return root;
}
void maxv(node *root)
{
    node *tam = root;
    while (tam->right != NULL)
    {
        tam = tam->right;
    }
    cout << tam->data << " ";
}
void minv(node *root)
{
    node *tam = root;
    while (tam->left != NULL)
    {
        tam = tam->left;
    }
    cout << tam->data << " ";
}
int main()
{
    faster();
    node *root = NULL;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        root = insertNode(root, x);
    }
    maxv(root);
    minv(root);
}