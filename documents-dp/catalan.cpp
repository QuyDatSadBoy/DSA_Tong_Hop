#include <iostream>
using namespace std;

// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n + 1];

    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;

    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }

    // Return last entry
    return catalan[n];
}

// Driver code
int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalanDP(i) << " ";
    return 0;
}

// C++ program for nth Catalan Number
#include <iostream>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n,
                                unsigned int k)
{
    unsigned long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] /
    // [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2 * n, n);

    // return 2nCn/(n+1)
    return c / (n + 1);
}

// Driver code
int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
    return 0;
}

#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;

// Function to print the number
void catalan(int n)
{
    cpp_int cat_ = 1;

    // For the first number
    cout << cat_ << " "; // C(0)

    // Iterate till N
    for (cpp_int i = 1; i <= n; i++)
    {
        // Calculate the number
        // and print it
        cat_ *= (4 * i - 2);
        cat_ /= (i + 1);
        cout << cat_ << " ";
    }
}

// Driver code
int main()
{
    int n = 5;

    // Function call
    catalan(n);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define bigint long long int

bigint findCatalan(int n)
{
    bigint b = 1;

    // calculating n!
    for (int i = 1; i <= n; i++)
    {
        b = b * i;
    }

    // calculating n! * n!
    b = b * b;

    bigint d = 1;

    // calculating (2n)!
    for (int i = 1; i <= 2 * n; i++)
    {
        d = d * i;
    }

    // calculating (2n)! / (n! * n!)
    bigint ans = d / b;

    // calculating (2n)! / ((n! * n!) * (n+1))
    ans = ans / (n + 1);
    return ans;
}

// Driver Code
int main()
{
    int n = 5;
    cout << findCatalan(n);
}

// This code is contributed by ajaymakvana.
