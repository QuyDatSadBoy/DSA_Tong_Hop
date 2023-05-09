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
void sprialOrder(node *root)
{
    queue<node *> qe;
    stack<ll> st1;
    qe.push(root);
    ll cnt = 1;
    while (!qe.empty())
    {
        auto top = qe.front();
        qe.pop();
        st1.push(top->data);
        if (top->right != NULL)
            qe.push(top->right);
        if (top->left != NULL)
            qe.push(top->left);
    }
    while (!st1.empty())
    {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;
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
        sprialOrder(root);
    }
}