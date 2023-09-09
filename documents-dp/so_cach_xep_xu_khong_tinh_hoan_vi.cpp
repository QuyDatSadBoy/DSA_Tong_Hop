#include <bits/stdc++.h>
using namespace std;

// Recursive function to count the numeber of distinct ways
// to make the sum by using n coins

int count(vector<int> &coins, int n, int sum,
          vector<vector<int>> &dp)
{
    // Base Case
    if (sum == 0)
        return dp[n][sum] = 1;

    // If number of coins is 0 or sum is less than 0 then
    // there is no way to make the sum.
    if (n == 0 || sum < 0)
        return 0;

    // If the subproblem is previously calculated then
    // simply return the result
    if (dp[n][sum] != -1)
        return dp[n][sum];

    // Two options for the current coin
    return dp[n][sum] = count(coins, n, sum - coins[n - 1], dp) + count(coins, n - 1, sum, dp);
}
int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n, sum;
        n = 3, sum = 5;
        vector<int> coins = {1, 2, 3};
        // 2d dp array to store previously calculated
        // results
        vector<vector<int>> dp(n + 1,
                               vector<int>(sum + 1, -1));
        int res = count(coins, n, sum, dp);
        cout << res << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

// Returns total distinct ways to make sum using n coins of
// different denominations
int count(vector<int> &coins, int n, int sum)
{
    // 2d dp array where n is the number of coin
    // denominations and sum is the target sum
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Represents the base case where the target sum is 0,
    // and there is only one way to make change: by not
    // selecting any coin
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            // Add the number of ways to make change without
            // using the current coin,
            dp[i][j] += dp[i - 1][j];

            if ((j - coins[i - 1]) >= 0)
            {

                // Add the number of ways to make change
                // using the current coin
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

// Driver Code
int main()
{
    vector<int> coins{1, 2, 3};
    int n = 3;
    int sum = 5;
    cout << count(coins, n, sum);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

// This code is
int count(int coins[], int n, int sum)
{
    // table[i] will be storing the number of solutions for
    // value i. We need sum+1 rows as the dp is
    // constructed in bottom up manner using the base case
    // (sum = 0)
    int dp[sum + 1];

    // Initialize all table values as 0
    memset(dp, 0, sizeof(dp));

    // Base case (If given value is 0)
    dp[0] = 1;

    // Pick all coins one by one and update the table[]
    // values after the index greater than or equal to the
    // value of the picked coin
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];
    return dp[sum];
}

// Driver Code
int main()
{
    int coins[] = {1, 2, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 5;
    cout << count(coins, n, sum);
    return 0;
}
