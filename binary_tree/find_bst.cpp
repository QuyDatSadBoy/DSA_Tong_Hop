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
bool find(node *root, ll k)
{
    if (root->data == k)
    {
        return true;
    }
    else
    {
        if (k < root->data && root->left != NULL)
            return find(root->left, k);
        else
        {
            if (k > root->data && root->right != NULL)
                return find(root->right, k);
            else
                return false;
        }
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
        ll x;
        cin >> x;
        root = insertNode(root, x);
    }
    ll k;
    cin >> k;
    if (find(root, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}