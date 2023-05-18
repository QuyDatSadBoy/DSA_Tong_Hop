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
        }
        else
        {
            if (root->left != NULL)
                insert_node(root->left, u, v, c);
            if (root->right != NULL)
                insert_node(root->right, u, v, c);
        }
    }
}
void print(node *root)
{
    queue<node *> qe;
    qe.push(root);
    while (!qe.empty())
    {
        node *top = qe.front();
        qe.pop();
        cout << top->data << " ";
        if (top->left != NULL)
            qe.push(top->left);
        if (top->right != NULL)
            qe.push(top->right);
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
        print(root);
        root = NULL;
        delete root;
    }
}