// C++ program to count number of ways to arrange three
// types of balls such that no two balls of same color
// are adjacent to each other
#include <bits/stdc++.h>
using namespace std;

// Returns count of arrangements where last placed ball is
// 'last'. 'last' is 0 for 'p', 1 for 'q' and 2 for 'r'
int countWays(int p, int q, int r, int last)
{
    // if number of balls of any color becomes less
    // than 0 the number of ways arrangements is 0.
    if (p < 0 || q < 0 || r < 0)
        return 0;

    // If last ball required is of type P and the number
    // of balls of P type is 1 while number of balls of
    // other color is 0 the number of ways is 1.
    if (p == 1 && q == 0 && r == 0 && last == 0)
        return 1;

    // Same case as above for 'q' and 'r'
    if (p == 0 && q == 1 && r == 0 && last == 1)
        return 1;
    if (p == 0 && q == 0 && r == 1 && last == 2)
        return 1;

    // if last ball required is P and the number of ways is
    // the sum of number of ways to form sequence with 'p-1' P
    // balls, q Q Balls and r R balls ending with Q and R.
    if (last == 0)
        return countWays(p - 1, q, r, 1) + countWays(p - 1, q, r, 2);

    // Same as above case for 'q' and 'r'
    if (last == 1)
        return countWays(p, q - 1, r, 0) + countWays(p, q - 1, r, 2);
    if (last == 2)
        return countWays(p, q, r - 1, 0) + countWays(p, q, r - 1, 1);
}

// Returns count of required arrangements
int countUtil(int p, int q, int r)
{
    // Three cases arise:
    return countWays(p, q, r, 0) + // Last required balls is type P
           countWays(p, q, r, 1) + // Last required balls is type Q
           countWays(p, q, r, 2);  // Last required balls is type R
}

// Driver code to test above
int main()
{
    int p = 1, q = 1, r = 1;
    printf("%d", countUtil(p, q, r));
    return 0;
}

// C++ program to count number of ways to arrange three
// types of balls such that no two balls of same color
// are adjacent to each other
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

// table to store to store results of subproblems
int dp[MAX][MAX][MAX][3];

// Returns count of arrangements where last placed ball is
// 'last'. 'last' is 0 for 'p', 1 for 'q' and 2 for 'r'
int countWays(int p, int q, int r, int last)
{
    // if number of balls of any color becomes less
    // than 0 the number of ways arrangements is 0.
    if (p < 0 || q < 0 || r < 0)
        return 0;

    // If last ball required is of type P and the number
    // of balls of P type is 1 while number of balls of
    // other color is 0 the number of ways is 1.
    if (p == 1 && q == 0 && r == 0 && last == 0)
        return 1;

    // Same case as above for 'q' and 'r'
    if (p == 0 && q == 1 && r == 0 && last == 1)
        return 1;
    if (p == 0 && q == 0 && r == 1 && last == 2)
        return 1;

    // If this subproblem is already evaluated
    if (dp[p][q][r][last] != -1)
        return dp[p][q][r][last];

    // if last ball required is P and the number of ways is
    // the sum of number of ways to form sequence with 'p-1' P
    // balls, q Q Balls and r R balls ending with Q and R.
    if (last == 0)
        dp[p][q][r][last] = countWays(p - 1, q, r, 1) + countWays(p - 1, q, r, 2);

    // Same as above case for 'q' and 'r'
    else if (last == 1)
        dp[p][q][r][last] = countWays(p, q - 1, r, 0) + countWays(p, q - 1, r, 2);
    else //(last==2)
        dp[p][q][r][last] = countWays(p, q, r - 1, 0) + countWays(p, q, r - 1, 1);

    return dp[p][q][r][last];
}

// Returns count of required arrangements
int countUtil(int p, int q, int r)
{
    // Initialize 'dp' array
    memset(dp, -1, sizeof(dp));

    // Three cases arise:
    return countWays(p, q, r, 0) + // Last required balls is type P
           countWays(p, q, r, 1) + // Last required balls is type Q
           countWays(p, q, r, 2);  // Last required balls is type R
}

// Driver code to test above
int main()
{
    int p = 1, q = 1, r = 1;
    printf("%d", countUtil(p, q, r));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

// Function to count the number of arrangements
int countUtil(int p, int q, int r)
{
    int dp[MAX][MAX][MAX];
    memset(dp, 0, sizeof(dp)); // Initializing the DP table with zeros

    // Base cases
    dp[1][0][0] = 1; // If only one 'p' is present
    dp[0][1][0] = 1; // If only one 'q' is present
    dp[0][0][1] = 1; // If only one 'r' is present

    // Fill the DP table
    for (int i = 0; i <= p; i++)
    {
        for (int j = 0; j <= q; j++)
        {
            for (int k = 0; k <= r; k++)
            {
                // Skip the base cases as they are already initialized
                if (i == 1 && j == 0 && k == 0)
                    continue;
                if (i == 0 && j == 1 && k == 0)
                    continue;
                if (i == 0 && j == 0 && k == 1)
                    continue;

                // Update DP values based on previous states
                if (i - 1 >= 0)
                    dp[i][j][k] += dp[i - 1][j][k]; // Add the count when using 'p'
                if (j - 1 >= 0)
                    dp[i][j][k] += dp[i][j - 1][k]; // Add the count when using 'q'
                if (k - 1 >= 0)
                    dp[i][j][k] += dp[i][j][k - 1]; // Add the count when using 'r'
            }
        }
    }

    return dp[p][q][r]; // Return the count of required arrangements
}

// Driver code to test above function
int main()
{
    int p = 1, q = 1, r = 1;
    printf("%d", countUtil(p, q, r));
    return 0;
}

// -- by bhardwajji
