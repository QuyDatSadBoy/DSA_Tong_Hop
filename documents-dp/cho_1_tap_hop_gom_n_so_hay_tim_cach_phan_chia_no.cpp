// Cho một tập hợp gồm n phần tử, hãy tìm số cách phân chia nó.

// Ví dụ:

// Đầu vào: n = 2

// Đầu ra: Số cách = 2

// Giải thích: Đặt tập hợp là {1, 2}

// { {1}, {2} }

// { {1, 2} }

// Đầu vào: n = 3

// Đầu ra: Số cách = 5

// Giải thích: Đặt tập hợp là {1, 2, 3}

// { {1}, {2}, {3} }

// { {1}, {2, 3} }

// { {2}, {1, 3} }

// { {3}, {1, 2} }

// { {1, 2, 3} }.

#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int s[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (j > i)
                s[i][j] = 0;
            else if (i == j)
                s[i][j] = 1;
            else if (i == 0 || j == 0)
                s[i][j] = 0;
            else
            {

                s[i][j] = j * s[i - 1][j] + s[i - 1][j - 1];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n + 1; i++)
    {
        ans += s[n][i];
    }
    cout << ans;

    return 0;
}

// A C++ program to find n'th Bell number
#include <iostream>
using namespace std;

int bellNumber(int n)
{
    int bell[n + 1][n + 1];
    bell[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // Explicitly fill for j = 0
        bell[i][0] = bell[i - 1][i - 1];

        // Fill for remaining values of j
        for (int j = 1; j <= i; j++)
            bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
    }
    return bell[n][0];
}

// Driver program
int main()
{
    for (int n = 0; n <= 5; n++)
        cout << "Bell Number " << n << " is "
             << bellNumber(n) << endl;
    return 0;
}
