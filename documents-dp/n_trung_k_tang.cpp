// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// A utility function to get
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Function to get minimum
// number of trials needed in worst
// case with n eggs and k floors
int eggDrop(int n, int k)
{
    // If there are no floors,
    // then no trials needed.
    // OR if there is one floor,
    // one trial needed.
    if (k == 1 || k == 0)
        return k;

    // We need k trials for one
    // egg and k floors
    if (n == 1)
        return k;

    int min = INT_MAX, x, res;

    // Consider all droppings from
    // 1st floor to kth floor and
    // return the minimum of these
    // values plus 1.
    for (x = 1; x <= k; x++)
    {
        res = max(eggDrop(n - 1, x - 1), eggDrop(n, k - x));
        if (res < min)
            min = res;
    }

    return min + 1;
}

// Driver code
int main()
{
    int n = 2, k = 10;
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k << " floors is "
         << eggDrop(n, k) << endl;
    return 0;
}

// This code is contributed
// by Akanksha Rai

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// A utility function to get
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* Function to get minimum
number of trials needed in worst
case with n eggs and k floors */
int eggDrop(int n, int k)
{
    /* A 2D table where entry
    eggFloor[i][j] will represent
    minimum number of trials needed for
    i eggs and j floors. */
    int eggFloor[n + 1][k + 1];
    int res;
    int i, j, x;

    // We need one trial for one floor and 0
    // trials for 0 floors
    for (i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    // We always need j trials for one egg
    // and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    // Fill rest of the entries in table using
    // optimal substructure property
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= k; j++)
        {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++)
            {
                res = 1 + max(eggFloor[i - 1][x - 1],
                              eggFloor[i][j - x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }

    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
}

// Driver code
int main()
{
    int n = 2, k = 36;
    cout << "\nMinimum number of trials "
            "in worst case with "
         << n << " eggs and " << k << " floors is "
         << eggDrop(n, k);
    return 0;
}

// this code is contributed by shivanisinghss2110

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> memo(MAX, vector<int>(MAX, -1));
int solveEggDrop(int n, int k)
{

    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    if (k == 1 || k == 0)
        return k;

    if (n == 1)
        return k;

    int min = INT_MAX, x, res;

    for (x = 1; x <= k; x++)
    {
        res = max(solveEggDrop(n - 1, x - 1),
                  solveEggDrop(n, k - x));
        if (res < min)
            min = res;
    }

    memo[n][k] = min + 1;
    return min + 1;
}

// Driver code
int main()
{

    int n = 2, k = 36;
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k << " floors is ";
    cout << solveEggDrop(n, k);
    return 0;
}

// contributed by Shivam Agrawal(shivamagrawal3)

// C++ program to find minimum number of trials in worst
// case.
#include <bits/stdc++.h>
using namespace std;

int minTrials(int n, int k)
{
    // Initialize 2D of size (k+1) * (n+1).
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    int m = 0; // Number of moves
    while (dp[m][n] < k)
    {
        m++;
        for (int x = 1; x <= n; x++)
        {
            dp[m][x] = 1 + dp[m - 1][x - 1] + dp[m - 1][x];
        }
    }
    return m;
}

/* Driver code*/
int main()
{
    int n = 2, k = 36;
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k << " floors is ";
    cout << minTrials(2, 36);
    return 0;
}

// This code is contributed by Arihant Jain (arihantjain01)

// C++ program to find minimum number of trials in worst
// case.
#include <bits/stdc++.h>
using namespace std;

int minTrials(int n, int k)
{
    // Initialize array of size (n+1) and m as moves.
    int dp[n + 1] = {0}, m;
    for (m = 0; dp[n] < k; m++)
    {
        for (int x = n; x > 0; x--)
        {
            dp[x] += 1 + dp[x - 1];
        }
    }
    return m;
}

/* Driver code*/
int main()
{
    int n = 2, k = 36;
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k << " floors is ";
    cout << minTrials(2, 36);
    return 0;
}

// This code is contributed by Arihant Jain (arihantjain01)
