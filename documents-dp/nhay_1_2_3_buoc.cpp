// C++ Program to find n-th stair using step size
// 1 or 2 or 3.
#include <iostream>
using namespace std;

class GFG
{

    // Returns count of ways to reach n-th stair
    // using 1 or 2 or 3 steps.
public:
    int findStep(int n)
    {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;

        else
            return findStep(n - 3) + findStep(n - 2) + findStep(n - 1);
    }
};

// Driver code
int main()
{
    GFG g;
    int n = 4;
    cout << g.findStep(n);
    return 0;
}

// This code is contributed by SoM15242

// A C++ program to count number of ways
// to reach n'th stair when
#include <iostream>
using namespace std;

// A recursive function used by countWays
int countWays(int n)
{
    int res[n + 1];
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i <= n; i++)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];

    return res[n];
}

// Driver program to test above functions
int main()
{
    int n = 4;
    cout << countWays(n);
    return 0;
}
// This code is contributed by shubhamsingh10

#include <bits/stdc++.h>
#define k 3
using namespace std;

// Multiply Two Matrix Function
vector<vector<int>> multiply(vector<vector<int>> A,
                             vector<vector<int>> B)
{
    // third matrix to store multiplication of Two matrix9*
    vector<vector<int>> C(k + 1, vector<int>(k + 1));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int x = 1; x <= k; x++)
            {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]));
            }
        }
    }

    return C;
}
// Optimal Way For finding pow(t,n)
// If n Is Odd then It Will be t*pow(t,n-1)
// else return pow(t,n/2)*pow(t,n/2)
vector<vector<int>> pow(vector<vector<int>> t, int n)
{
    // base Case
    if (n == 1)
    {
        return t;
    }
    // Recurrence Case
    if (n & 1)
    {
        return multiply(t, pow(t, n - 1));
    }
    else
    {
        vector<vector<int>> X = pow(t, n / 2);
        return multiply(X, X);
    }
}

int compute(int n)
{
    // base Case
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Function Vector(indexing 1 )
    // that is [1,2]
    int f1[k + 1] = {};
    f1[1] = 1;
    f1[2] = 2;
    f1[3] = 4;

    // Constructing Transformation Matrix that will be
    /*[[0,1,0],[0,0,1],[3,2,1]]
     */
    vector<vector<int>> t(k + 1, vector<int>(k + 1));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < k)
            {
                // Store 1 in cell that is next to diagonal
                // of Matrix else Store 0 in cell
                if (j == i + 1)
                {
                    t[i][j] = 1;
                }
                else
                {
                    t[i][j] = 0;
                }
                continue;
            }
            // Last Row - store the Coefficients in reverse
            // order
            t[i][j] = 1;
        }
    }

    // Computing T^(n-1) and Setting Transformation matrix T
    // to T^(n-1)
    t = pow(t, n - 1);
    int sum = 0;
    // Computing first cell (row=1,col=1) For Resultant
    // Matrix TXF
    for (int i = 1; i <= k; i++)
    {
        sum += t[1][i] * f1[i];
    }
    return sum;
}
int main()
{
    int n = 4;
    cout << compute(n) << endl;
    n = 5;
    cout << compute(n) << endl;
    n = 10;
    cout << compute(n) << endl;

    return 0;
}

// A C++ program to count number of ways
// to reach nth stair when
#include <iostream>
using namespace std;

// A recursive function used by countWays
int countWays(int n)
{
    int a = 1, b = 2, c = 4; // declaring three variables
                             // and holding the ways
                             // for first three stairs
    int d = 0;               // fourth variable
    if (n == 0 || n == 1 || n == 2)
        return n;
    if (n == 3)
        return c;

    for (int i = 4; i <= n; i++)
    {                  // starting from 4 as
        d = c + b + a; // already counted for 3 stairs
        a = b;
        b = c;
        c = d;
    }
    return d;
}

// Driver program to test above functions
int main()
{
    int n = 4;
    cout << countWays(n);
    return 0;
}
// This code is contributed by Naveen Shah

// C++ Program to find n-th stair using step size
// 1 or 2 or 3.
#include <bits/stdc++.h>
using namespace std;

class GFG
{
private:
    int findStepHelper(int n, vector<int> &dp)
    {
        // Base Case
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;
        // If subproblems are already calculated
        // then return it
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // store the subproblems in the vector
        return dp[n] = findStepHelper(n - 3, dp) + findStepHelper(n - 2, dp) + findStepHelper(n - 1, dp);
    }

    // Returns count of ways to reach n-th stair
    // using 1 or 2 or 3 steps.
public:
    int findStep(int n)
    {
        vector<int> dp(n + 1, -1);
        return findStepHelper(n, dp);
    }
};

// Driver code
int main()
{
    GFG g;
    int n = 4;

    cout << g.findStep(n);
    return 0;
}
