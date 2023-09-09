// Cho N, đếm số cách biểu diễn N bằng tổng của 1, 3 và 4.

// Input :  N = 4
// Output : 4
// Explanation: 1+1+1+1
//              1+3
//              3+1
//              4

// Input : N = 5
// Output : 6
// Explanation: 1 + 1 + 1 + 1 + 1
//              1 + 4
//              4 + 1
//              1 + 1 + 3
//              1 + 3 + 1
//              3 + 1 + 1

// C++ program to illustrate the number of
// ways to represent N as sum of 1, 3 and 4.
#include <bits/stdc++.h>
using namespace std;

// function to count the number of
// ways to represent n as sum of 1, 3 and 4
int countWays(int n)
{
    int DP[n + 1];

    // base cases
    DP[0] = DP[1] = DP[2] = 1;
    DP[3] = 2;

    // iterate for all values from 4 to n
    for (int i = 4; i <= n; i++)
        DP[i] = DP[i - 1] + DP[i - 3] + DP[i - 4];

    return DP[n];
}

// driver code
int main()
{
    int n = 10;
    cout << countWays(n);
    return 0;
}

// C++ program to illustrate the number of ways to represent N as sum of 1, 3 and 4.

#include <bits/stdc++.h>
using namespace std;

// function to count the number of ways to represent n as sum of 1, 3 and 4
int countWays(int n)
{
    int dp_i, dp_i_1, dp_i_2, dp_i_3, dp_i_4;

    if (n == 0 || n == 1 || n == 2)
        return 1;
    else if (n == 3)
        return 2;

    // base cases
    dp_i_4 = dp_i_3 = dp_i_2 = 1;
    dp_i_1 = 2;

    // iterate for all values from 4 to n
    for (int i = 4; i <= n; i++)
    {
        dp_i = dp_i_1 + dp_i_3 + dp_i_4;
        // Updating Variable value so in next Iteration they become relevant
        dp_i_4 = dp_i_3;
        dp_i_3 = dp_i_2;
        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }

    return dp_i;
}

// driver code
int main()
{
    int n = 10;
    cout << countWays(n);
    return 0;
}
