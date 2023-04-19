#include <iostream>
#include <vector>
using namespace std;

vector<int> ke[21];
int visited[21] = {};
int x[21] = {}, n, v, a[21][21] = {};

void Hal(int k)
{
    for (int i : ke[x[k - 1]])
    {
        if (k == n + 1 && i == x[1])
        {
            for (int j = 1; j <= n; j++)
                cout << x[j] << " ";
            cout << x[1] << endl;
        }
        else if (visited[i] == 0)
        {
            x[k] = i;
            visited[i] = 1;
            Hal(k + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
                ke[i].push_back(j);
        }
    }

    x[1] = v;
    visited[v] = 1;
    Hal(2);
}