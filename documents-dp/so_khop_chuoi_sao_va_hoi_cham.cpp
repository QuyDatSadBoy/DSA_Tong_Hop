#include <iostream>
using namespace std;

bool isMatch(string s, string p)
{
    // dry run this sample case on paper , if unable to understand what soln does
    //  p = "a*bc" s = "abcbc"
    int sIdx = 0, pIdx = 0, lastWildcardIdx = -1, sBacktrackIdx = -1, nextToWildcardIdx = -1;
    while (sIdx < s.size())
    {
        if (pIdx < p.size() && (p[pIdx] == '?' || p[pIdx] == s[sIdx]))
        {
            // chars match
            ++sIdx;
            ++pIdx;
        }
        else if (pIdx < p.size() && p[pIdx] == '*')
        {
            // wildcard, so chars match - store index.
            lastWildcardIdx = pIdx;
            nextToWildcardIdx = ++pIdx;
            sBacktrackIdx = sIdx;

            // storing the pidx+1 as from there I want to match the remaining pattern
        }
        else if (lastWildcardIdx == -1)
        {
            // no match, and no wildcard has been found.
            return false;
        }
        else
        {
            // backtrack - no match, but a previous wildcard was found.
            pIdx = nextToWildcardIdx;
            sIdx = ++sBacktrackIdx;
            // backtrack string from previousbacktrackidx + 1 index to see if then new pidx and sidx have same chars, if that is the case that means wildcard can absorb the chars in b/w and still further we can run the algo, if at later stage it fails we can backtrack
        }
    }
    for (int i = pIdx; i < p.size(); i++)
    {
        if (p[i] != '*')
            return false;
    }
    return true;
    // true if every remaining char in p is wildcard
}

int main()
{

    string str = "baaabab";
    string pattern = "*****ba*****ab";
    // char pattern[] = "ba*****ab";
    // char pattern[] = "ba*ab";
    // char pattern[] = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";

    if (isMatch(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

// C++ program to implement wildcard
// pattern matching algorithm
#include <bits/stdc++.h>
using namespace std;

// Function that matches input str with
// given wildcard pattern
bool strmatch(char str[], char pattern[], int n, int m)
{
    // empty pattern can only match with
    // empty string
    if (m == 0)
        return (n == 0);

    // lookup table for storing results of
    // subproblems
    bool lookup[n + 1][m + 1];

    // initialize lookup table to false
    memset(lookup, false, sizeof(lookup));

    // empty pattern can match with empty string
    lookup[0][0] = true;

    // Only '*' can match with empty string
    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];

    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Two cases if we see a '*'
            // a) We ignore ‘*’ character and move
            // to next character in the pattern,
            //	 i.e., ‘*’ indicates an empty sequence.
            // b) '*' character matches with ith
            //	 character in input
            if (pattern[j - 1] == '*')
                lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];

            // Current characters are considered as
            // matching in two cases
            // (a) current character of pattern is '?'
            // (b) characters actually match
            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];

            // If characters don't match
            else
                lookup[i][j] = false;
        }
    }

    return lookup[n][m];
}

int main()
{
    char str[] = "baaabab";
    char pattern[] = "*****ba*****ab";
    // char pattern[] = "ba*****ab";
    // char pattern[] = "ba*ab";
    // char pattern[] = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";

    if (strmatch(str, pattern, strlen(str),
                 strlen(pattern)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

// C++ program to implement wildcard
// pattern matching algorithm

#include <bits/stdc++.h>

using namespace std;

// Function that matches input str with
// given wildcard pattern
vector<vector<int>> dp;
int finding(string &s, string &p, int n, int m)
{
    // return 1 if n and m are negative
    if (n < 0 && m < 0)
        return 1;

    // return 0 if m is negative
    if (m < 0)
        return 0;

    // return n if n is negative
    if (n < 0)
    {
        // while m is positive
        while (m >= 0)
        {
            if (p[m] != '*')
                return 0;
            m--;
        }
        return 1;
    }

    // if dp state is not visited
    if (dp[n][m] == -1)
    {
        if (p[m] == '*')
        {
            return dp[n][m] = finding(s, p, n - 1, m) || finding(s, p, n, m - 1);
        }
        else
        {
            if (p[m] != s[n] && p[m] != '?')
                return dp[n][m] = 0;
            else
                return dp[n][m] = finding(s, p, n - 1, m - 1);
        }
    }

    // return dp[n][m] if dp state is previsited
    return dp[n][m];
}

bool isMatch(string s, string p)
{
    dp.clear();

    // resize the dp array
    dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
    return dp[s.size()][p.size()] = finding(s, p, s.size() - 1, p.size() - 1);
}

// Driver code
int main()
{
    string str = "baaabab";
    string pattern = "*****ba*****ab";
    // char pattern[] = "ba*****ab";
    // char pattern[] = "ba*ab";
    // char pattern[] = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";

    if (isMatch(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

// C++ program to implement wildcard
// pattern matching algorithm

#include <bits/stdc++.h>

using namespace std;

// Function that matches input str with
// given wildcard pattern
vector<vector<int>> dp;
int finding(string &s, string &p, int n, int m)
{
    // return 1 if n and m are negative
    if (n < 0 && m < 0)
        return 1;

    // return 0 if m is negative
    if (m < 0)
        return 0;

    // return n if n is negative
    if (n < 0)
    {
        // while m is positive
        while (m >= 0)
        {
            if (p[m] != '*')
                return 0;
            m--;
        }
        return 1;
    }

    // if dp state is not visited
    if (dp[n][m] == -1)
    {
        if (p[m] == '*')
        {
            return dp[n][m] = finding(s, p, n - 1, m) || finding(s, p, n, m - 1);
        }
        else
        {
            if (p[m] != s[n] && p[m] != '?')
                return dp[n][m] = 0;
            else
                return dp[n][m] = finding(s, p, n - 1, m - 1);
        }
    }

    // return dp[n][m] if dp state is previsited
    return dp[n][m];
}

bool isMatch(string s, string p)
{
    dp.clear();

    // resize the dp array
    dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
    return dp[s.size()][p.size()] = finding(s, p, s.size() - 1, p.size() - 1);
}

// Driver code
int main()
{
    string str = "baaabab";
    string pattern = "*****ba*****ab";
    // char pattern[] = "ba*****ab";
    // char pattern[] = "ba*ab";
    // char pattern[] = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";

    if (isMatch(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

// C++ program to implement wildcard
// pattern matching algorithm
#include <bits/stdc++.h>
using namespace std;

// Function that matches input str with
// given wildcard pattern
bool strmatch(char str[], char pattern[], int m, int n)
{
    // lookup table for storing results of
    // subproblems
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    // empty pattern can match with empty string
    prev[0] = true;

    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++)
    {

        bool flag = true;
        for (int ii = 1; ii < i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag; // for every row we are assigning
                        // 0th column value.
        for (int j = 1; j <= m; j++)
        {
            // Two cases if we see a '*'
            // a) We ignore ‘*’ character and move
            // to next character in the pattern,
            //	 i.e., ‘*’ indicates an empty sequence.
            // b) '*' character matches with ith
            //	 character in input
            if (pattern[i - 1] == '*')
                curr[j] = curr[j - 1] || prev[j];

            // Current characters are considered as
            // matching in two cases
            // (a) current character of pattern is '?'
            // (b) characters actually match
            else if (pattern[i - 1] == '?' || str[j - 1] == pattern[i - 1])
                curr[j] = prev[j - 1];

            // If characters don't match
            else
                curr[j] = false;
        }
        prev = curr;
    }

    return prev[m];
}

int main()
{
    char str[] = "baaabab";
    char pattern[] = "*****ba*****ab";
    // char pattern[] = "ba*****ab";
    // char pattern[] = "ba*ab";
    // char pattern[] = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";

    if (strmatch(str, pattern, strlen(str),
                 strlen(pattern)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
