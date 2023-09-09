// C++ program to find the longest repeating
// subsequence
#include <iostream>
#include <string>
using namespace std;

// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();

    // Create and initialize DP table
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    // Fill dp table (similar to LCS loops)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // If characters match and indexes are
            // not same
            if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];

            // If characters do not match
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][n];
}

// Driver Program
int main()
{
    string str = "aabb";
    cout << "The length of the largest subsequence that"
            " repeats itself is : "
         << findLongestRepeatingSubSeq(str);
    return 0;
}

// C++ program to find the longest repeating
// subsequence using recursion
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.

int findLongestRepeatingSubSeq(string X, int m, int n)
{

    if (dp[m][n] != -1)
        return dp[m][n];

    // return if we have reached the end of either string
    if (m == 0 || n == 0)
        return dp[m][n] = 0;

    // if characters at index m and n matches
    // and index is different
    if (X[m - 1] == X[n - 1] && m != n)
        return dp[m][n] = findLongestRepeatingSubSeq(X,
                                                     m - 1, n - 1) +
                          1;

    // else if characters at index m and n don't match
    return dp[m][n] = max(findLongestRepeatingSubSeq(X, m, n - 1),
                          findLongestRepeatingSubSeq(X, m - 1, n));
}

// Longest Repeated Subsequence Problem
int main()
{
    string str = "aabb";
    int m = str.length();

    memset(dp, -1, sizeof(dp));
    cout << "The length of the largest subsequence that"
            " repeats itself is : "
         << findLongestRepeatingSubSeq(str, m, m);

    return 0;
    // this code is contributed by Kushdeep Mittal
}

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int lrs(string s1, int i, int j, vector<vector<int>> &dp)
{

    // return if we have reached the
    // end of either string
    if (i >= s1.length() || j >= s1.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // while dp[i][j] is not computed earlier
    if (dp[i][j] == -1)
    {

        // if characters at index m and n matches
        // and index is different
        // Index should not match
        if (s1[i] == s1[j] && i != j)
            dp[i][j] = 1 + lrs(s1, i + 1, j + 1, dp);

        // else if characters at index m and n don't match
        else
            dp[i][j] = max(lrs(s1, i, j + 1, dp),
                           lrs(s1, i + 1, j, dp));
    }

    // return answer
    return dp[i][j];
}

// Driver Code
int main()
{

    string s1 = "aabb";

    // Reversing the same string
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(1000, vector<int>(1000, -1));
    cout << "LENGTH OF LONGEST REPEATING SUBSEQUENCE IS : " << lrs(s1, 0, 0, dp);
}

// This code is contributed by shinjanpatra

#include <bits/stdc++.h>
using namespace std;

// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();

    // Create and initialize DP table
    int dp[n + 1] = {0};

    // Fill dp table (similar to LCS loops)
    for (int i = 1; i <= n; i++)
    {
        int new_a[n + 1] = {0};
        for (int j = 1; j <= n; j++)
        {
            // If characters match and indexes are
            // not same
            if (str[i - 1] == str[j - 1] && i != j)
            {
                new_a[j] = 1 + dp[j - 1];
            }

            // If characters do not match
            else
            {
                new_a[j] = max(dp[j], new_a[j - 1]);
            }
        }
        for (int j = 0; j <= n; j++)
            dp[j] = new_a[j];
    }
    return dp[n];
}

// Driver Program
int main()
{
    string str = "aabb";
    cout << "The length of the largest subsequence that"
         << " repeats itself is : "
         << findLongestRepeatingSubSeq(str);
    return 0;
}
