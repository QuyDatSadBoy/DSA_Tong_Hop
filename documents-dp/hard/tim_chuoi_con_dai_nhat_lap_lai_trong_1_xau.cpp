// Given a string str, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. If there exists more than one such substring return any of them.

// Examples:

// Input : str = "geeksforgeeks"
// Output : geeks

// Input : str = "aab"
// Output : a

// Input : str = "aabaabaaba"
// Output : aaba

// Input : str = "aaaaaaaaaaa"
// Output : aaaaa

// Input : str = "banana"
// Output : an
//          or na
// Naive Solution : The problem can be solved easily by taking all the possible substrings and for all the substrings check it for the remaining(non-overlapping) string if there exists an identical substring. There are O(n2) total substrings and checking them against the remaining string will take O(n) time. So overall time complexity of above solution is O(n3).

// Dynamic Programming : This problem can be solved in O(n2) time using Dynamic Programming. The basic idea is to find the longest repeating suffix for all prefixes in the string str.

// Length of longest non-repeating substring can be recursively
// defined as below.

// LCSRe(i, j) stores length of the matching and
//             non-overlapping substrings ending
//             with i'th and j'th characters.

// If str[i-1] == str[j-1] && (j-i) > LCSRe(i-1, j-1)
//      LCSRe(i, j) = LCSRe(i-1, j-1) + 1,
// Else
//      LCSRe(i, j) = 0

// Where i varies from 1 to n and
//       j varies from i+1 to n
// To avoid overlapping we have to ensure that the length of suffix is less than (j-i) at any instant.
// The maximum value of LCSRe(i, j) provides the length of the longest repeating substring and the substring itself can be found using the length and the ending index of the common suffix.

// Below is the implementation of the recurrence.

// C++ program to find the longest repeated
// non-overlapping substring
#include <bits/stdc++.h>
using namespace std;

// Returns the longest repeating non-overlapping
// substring in str
string longestRepeatedSubstring(string str)
{
    int n = str.length();
    int LCSRe[n + 1][n + 1];

    // Setting all to 0
    memset(LCSRe, 0, sizeof(LCSRe));

    string res;         // To store result
    int res_length = 0; // To store length of result

    // building table in bottom-up manner
    int i, index = 0;
    for (i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // (j-i) > LCSRe[i-1][j-1] to remove
            // overlapping
            if (str[i - 1] == str[j - 1] &&
                LCSRe[i - 1][j - 1] < (j - i))
            {
                LCSRe[i][j] = LCSRe[i - 1][j - 1] + 1;

                // updating maximum length of the
                // substring and updating the finishing
                // index of the suffix
                if (LCSRe[i][j] > res_length)
                {
                    res_length = LCSRe[i][j];
                    index = max(i, index);
                }
            }
            else
                LCSRe[i][j] = 0;
        }
    }

    // If we have non-empty result, then insert all
    // characters from first character to last
    // character of string
    if (res_length > 0)
        for (i = index - res_length + 1; i <= index; i++)
            res.push_back(str[i - 1]);

    return res;
}

// Driver program to test the above function
int main()
{
    string str = "geeksforgeeks";
    cout << longestRepeatedSubstring(str);
    return 0;
}
