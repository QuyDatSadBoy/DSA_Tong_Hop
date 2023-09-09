// C++ program to print distinct subset sums of
// a given array.
#include <bits/stdc++.h>
using namespace std;

// sum denotes the current sum of the subset
// currindex denotes the index we have reached in
// the given array
void distSumRec(int arr[], int n, int sum,
                int currindex, unordered_set<int> &s)
{
    if (currindex > n)
        return;

    if (currindex == n)
    {
        s.insert(sum);
        return;
    }

    distSumRec(arr, n, sum + arr[currindex],
               currindex + 1, s);
    distSumRec(arr, n, sum, currindex + 1, s);
}

// This function mainly calls recursive function
// distSumRec() to generate distinct sum subsets.
// And finally prints the generated subsets.
void printDistSum(int arr[], int n)
{
    unordered_set<int> s;
    distSumRec(arr, n, 0, 0, s);

    // Print the result
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
}

// Driver code
int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printDistSum(arr, n);
    return 0;
}

// C++ program to print distinct subset sums of
// a given array.
#include <bits/stdc++.h>
using namespace std;

// Uses Dynamic Programming to find distinct
// subset sums
void printDistSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // dp[i][j] would be true if arr[0..i-1] has
    // a subset with sum equal to j.
    bool dp[n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));

    // There is always a subset with 0 sum
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill dp[][] in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        dp[i][arr[i - 1]] = true;
        for (int j = 1; j <= sum; j++)
        {
            // Sums that were achievable
            // without current array element
            if (dp[i - 1][j] == true)
            {
                dp[i][j] = true;
                dp[i][j + arr[i - 1]] = true;
            }
        }
    }

    // Print last row elements
    for (int j = 0; j <= sum; j++)
        if (dp[n][j] == true)
            cout << j << " ";
}

// Driver code
int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printDistSum(arr, n);
    return 0;
}

// C++ Program to Demonstrate Bitset Optimised Knapsack
// Solution

#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
    // Input Vector
    vector<int> a = {2, 3, 4, 5, 6};

    // we have to make a constant size for bit-set
    // and to be safe keep it significantly high
    int n = a.size();
    const int mx = 40;

    // bitset of size mx, dp[i] is 1 if sum i is possible
    // and 0 otherwise
    bitset<mx> dp;
    // sum 0 is always possible
    dp[0] = 1;

    // dp transitions as explained in article
    for (int i = 0; i < n; ++i)
    {
        dp |= dp << a[i];
    }

    // print all the 1s in bit-set, this will be the
    // all the unique sums possible
    for (int i = 0; i <= mx; i++)
    {
        if (dp[i] == 1)
            cout << i << " ";
    }
}

// code is contributed by sarvjot singh
