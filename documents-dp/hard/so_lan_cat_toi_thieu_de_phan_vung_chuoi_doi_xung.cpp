// C++ Code for Palindrome Partitioning
// Problem

#include <bits/stdc++.h>
using namespace std;

// Function to Check if a substring is a palindrome
bool isPalindrome(string String, int i, int j)
{
    while (i < j)
    {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Function to find the minimum number of cuts needed for
// palindrome partitioning
int minPalPartion(string String, int i, int j)
{
    // Base case: If the substring is empty or a palindrome,
    // no cuts needed
    if (i >= j || isPalindrome(String, i, j))
        return 0;

    int ans = INT_MAX, count;

    // Iterate through all possible partitions and find the
    // minimum cuts needed
    for (int k = i; k < j; k++)
    {
        count = minPalPartion(String, i, k) + minPalPartion(String, k + 1, j) + 1;
        ans = min(ans, count);
    }

    return ans;
}

// Driver code
int main()
{
    string str = "ababbbabbababa";

    // Find the minimum cuts needed for palindrome
    // partitioning and display the result
    cout
        << "Min cuts needed for Palindrome Partitioning is "
        << minPalPartion(str, 0, str.length() - 1) << endl;

    return 0;
}

// Dynamic Programming Solution for
// Palindrome Partitioning Problem
#include <bits/stdc++.h>
using namespace std;

// Returns the minimum number of cuts
// needed to partition a string
// such that every part is a palindrome
int minPalPartion(string str)
{
    // Get the length of the string
    int n = str.length();

    // Create two arrays to build the solution in bottom up
    // manner

    // C[i][j] = Minimum number of cuts needed for
    // palindrome partitioning of substring str[i..j]
    int C[n][n];

    // P[i][j] = true if substring str[i..j] is palindrome,
    // else false
    bool P[n][n];

    // Note that C[i][j] is 0 if P[i][j] is true

    // Every substring of length 1 is a palindrome
    for (int i = 0; i < n; i++)
    {
        P[i][i] = true;
        C[i][i] = 0;
    }

    // L is substring length. Build the
    // solution in bottom up manner by
    // considering all substrings of
    // length starting from 2 to n.
    // The loop structure is same as Matrix
    // Chain Multiplication problem
    // (See https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/)
    for (int L = 2; L <= n; L++)
    {

        // For substring of length L, set
        // different possible starting indexes
        for (int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1; // Set ending index

            // If L is 2, then we just need to
            // compare two characters. Else
            // need to check two corner characters
            // and value of P[i+1][j-1]
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];

            // IF str[i..j] is palindrome, then C[i][j] is 0
            if (P[i][j] == true)
                C[i][j] = 0;
            else
            {

                // Make a cut at every possible
                // location starting from i to j,
                // and get the minimum cost cut.
                C[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                    C[i][j] = min(
                        C[i][j], C[i][k] + C[k + 1][j] + 1);
            }
        }
    }

    // Return the min cut value for
    // complete string. i.e., str[0..n-1]
    return C[0][n - 1];
}

// Driver code
int main()
{
    string str = "ababbbabbababa";
    cout << "Min cuts needed for Palindrome"
            " Partitioning is "
         << minPalPartion(str);
    return 0;
}

// This code is contributed by rathbhupendra

#include <bits/stdc++.h>
using namespace std;

// Function to generate all possible palindromic substring
bool generatePalindrome(string &s,
                        vector<vector<bool>> &pal)
{
    int n = s.size();

    // Initialize the palindrome matrix for single
    // characters
    for (int i = 0; i < n; i++)
    {
        pal[i][i] = true;
    }

    // Iterate over different lengths of substrings
    for (int len = 2; len <= n; len++)
    {
        // Iterate over the starting positions of substrings
        // of current length
        for (int i = 0; i <= n - len; i++)
        {

            // Calculate the ending position of the
            // substring
            int j = i + len - 1;

            // Check if the characters at the starting and
            // ending positions are equal and if the
            // substring between them is a palindrome or a
            // single character
            if (s[i] == s[j] && (len == 2 || pal[i + 1][j - 1]))
            {

                // Mark the substring from i to j as a
                // palindrome
                pal[i][j] = true;
            }
        }
    }
}

// Function to calculate the minimum number of cuts required
// to make all substrings of 's' palindromic
int minCut(string s)
{
    if (s.empty())
        return 0;
    int n = s.size();

    // 2D vector to store whether substring [i, j] is a
    // palindrome
    vector<vector<bool>> pal(n, vector<bool>(n, false));

    generatePalindrome(s, pal);

    // vector to store minimum cuts required to make
    // substring [i, n-1] palindromic
    vector<int> minCutDp(n, INT_MAX);

    // There is no cut required for single character
    // as it is always palindrome
    minCutDp[0] = 0;

    // Iterate over the given string
    for (int i = 1; i < n; i++)
    {

        // Check if string 0 to i is palindrome.
        // Then minCut require will be 0.
        if (pal[0][i])
        {
            minCutDp[i] = 0;
        }
        else
        {
            for (int j = i; j >= 1; j--)
            {

                // If s[i] and s[j] are equal and the inner
                // substring [i+1, j-1] is a palindrome or
                // it has a length of 1
                if (pal[j][i])
                {

                    // Update the minimum cuts required if
                    // cutting at position 'j+1' results in
                    // a smaller value
                    if (minCutDp[j - 1] + 1 < minCutDp[i])
                        minCutDp[i] = minCutDp[j - 1] + 1;
                }
            }
        }
    }

    // Return the minimum cuts required for the entire
    // string 's'
    return minCutDp[n - 1];
}

int main()
{
    string str = "ababbbabbababa";

    int cuts = minCut(str);
    cout << "Minimum cuts required: " << cuts << endl;
    return 0;
}
