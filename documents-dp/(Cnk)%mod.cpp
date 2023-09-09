// A Dynamic Programming based solution that uses
// table C[][] to calculate the Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

// Prototype of a utility function that
// returns minimum of two integers
int min(int a, int b);

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;

    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously
            // stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

// A utility function to return
// minimum of two integers
int min(int a, int b) { return (a < b) ? a : b; }

// Driver Code
int main()
{
    int n = 5, k = 2;
    cout << "Value of C[" << n << "][" << k << "] is "
         << binomialCoeff(n, k);
}

// This code is contributed by Shivi_Aggarwal

// C++ program for space optimized Dynamic Programming
// Solution of Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k)
{
    int C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++)
    {

        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

/* Driver code*/
int main()
{
    int n = 5, k = 2;
    cout << "Value of C(" << n << "," << k << ")"
         << "is " << binomialCoeff(n, k);
    return 0;
}

// This code is contributed by shivanisinghss2110

// A Dynamic Programming based
// solution that uses
// table dp[][] to calculate
// the Binomial Coefficient
// A naive recursive approach
// with table C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeffUtil(int n, int k, int **dp)
{
    // If value in lookup table then return
    if (dp[n][k] != -1) //
        return dp[n][k];

    // store value in a table before return
    if (k == 0)
    {
        dp[n][k] = 1;
        return dp[n][k];
    }

    // store value in table before return
    if (k == n)
    {
        dp[n][k] = 1;
        return dp[n][k];
    }

    // save value in lookup table before return
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) +
               binomialCoeffUtil(n - 1, k, dp);
    return dp[n][k];
}

int binomialCoeff(int n, int k)
{
    int **dp; // make a temporary lookup table
    dp = new int *[n + 1];

    // loop to create table dynamically
    for (int i = 0; i < (n + 1); i++)
    {
        dp[i] = new int[k + 1];
    }

    // nested loop to initialise the table with -1
    for (int i = 0; i < (n + 1); i++)
    {
        for (int j = 0; j < (k + 1); j++)
        {
            dp[i][j] = -1;
        }
    }

    return binomialCoeffUtil(n, k, dp);
}

/* Driver code*/
int main()
{
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeff(n, k) << endl;
    return 0;
}

// This is code is contributed by MOHAMMAD MUDASSIR

// C++ program to find gcd of
// two numbers in O(log(min(a,b)))

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int nCr(int n, int r)
{
    // base case
    if (r > n)
        return 0;

    // C(n,r) = C(n,n-r)
    if (r > n - r)
        r = n - r;

    int mod = 1000000007;

    // array of elements from n-r+1 to n
    int arr[r];

    for (int i = n - r + 1; i <= n; i++)
    {
        arr[i + r - n - 1] = i;
    }

    long int ans = 1;
    // for numbers from 1 to r find arr[j],
    // such that gcd(i,arr[j])>1
    for (int k = 1; k < r + 1; k++)
    {
        int j = 0, i = k;
        while (j < r)
        {
            int x = gcd(i, arr[j]);
            if (x > 1)
            {
                // if gcd>1, divide both by gcd
                arr[j] /= x;
                i /= x;
            }

            // if i becomes 1, no need to search arr
            if (i == 1)
                break;
            j += 1;
        }
    }

    // single pass to multiply the numerator
    for (int i : arr)
        ans = (ans * i) % mod;
    return (int)ans;
}

int main()
{
    int n = 5, r = 2;
    cout << "Value of C(" << n << ", " << r << ") is "
         << nCr(n, r) << "\n";
    return 0;
}

// This code is contributed by rajsanghavi9.

#include <bits/stdc++.h>
using namespace std;

// pow(base,exp,mod) is used to find
// (base^exp)%mod fast -> O(log(exp))
long int pow(long int b, long int exp, long int mod)
{
    long int ret = 1;

    while (exp > 0)
    {
        if ((exp & 1) > 0)
            ret = (ret * b) % mod;
        b = (b * b) % mod;
        exp >>= 1;
    }

    return ret;
}

int nCr(int n, int r)
{
    // base case
    if (r > n)
        return 0;

    // C(n,r) = C(n,n-r) Complexity for
    // this code is lesser for lower n-r
    if (n - r > r)
        r = n - r;

    // list to smallest prime factor
    // of each number from 1 to n
    int SPF[n + 1];

    // set smallest prime factor of each
    // number as itself
    for (int i = 1; i <= n; i++)
        SPF[i] = i;

    // set smallest prime factor of all
    // even numbers as 2
    for (int i = 4; i <= n; i += 2)
        SPF[i] = 2;

    for (int i = 3; i * i < n + 1; i += 2)
    {

        // Check if i is prime
        if (SPF[i] == i)
        {
            // All multiples of i are
            // composite (and divisible by
            // i) so add i to their prime
            // factorization getpow(j,i)
            // times
            for (int j = i * i; j < n + 1; j += i)
                if (SPF[j] == j)
                {
                    SPF[j] = i;
                }
        }
    }
    // Hash Map to store power of
    // each prime in C(n,r)
    map<int, int> prime_pow;

    // For numerator count frequency of each prime factor
    for (int i = r + 1; i < n + 1; i++)
    {

        int t = i;

        // Recursive division to find
        // prime factorization of i
        while (t > 1)
        {
            if (!prime_pow[SPF[t]])
            {
                prime_pow[SPF[t]] = 1;
            }
            else
                prime_pow[SPF[t]]++;
            // prime_pow.put(SPF[t],
            // prime_pow.getOrDefault(SPF[t], 0)
            // + 1);
            t /= SPF[t];
        }
    }

    // For denominator subtract the power of
    // each prime factor
    for (int i = 1; i < n - r + 1; i++)
    {
        int t = i;

        // Recursive division to find
        // prime factorization of i
        while (t > 1)
        {
            prime_pow[SPF[t]]--;
            // prime_pow.put(SPF[t],
            // prime_pow.get(SPF[t]) - 1);
            t /= SPF[t];
        }
    }

    // long because mod is large and a%mod
    // * b%mod can overflow int
    long int ans = 1, mod = 1000000007;

    // use (a*b)%mod = (a%mod * b%mod)%mod
    for (auto it : prime_pow)

        // pow(base,exp,mod) is used to
        // find (base^exp)%mod fast
        ans = (ans * pow(it.first, prime_pow[it.first], mod)) % mod;
    return (int)ans;
}

int main()
{
    int n = 5, r = 2;
    cout << "Value of C(" << n << ", " << r << ") is "
         << nCr(n, r) << "\n";
    return 0;
}

// This code is contributed by rajsanghavi9.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find binomial
// coefficient
int binomialCoeff(int n, int r)
{

    if (r > n)
        return 0;
    long long int m = 1000000007;
    long long int inv[r + 1] = {0};
    inv[0] = 1;
    if (r + 1 >= 2)
        inv[1] = 1;

    // Getting the modular inversion
    // for all the numbers
    // from 2 to r with respect to m
    // here m = 1000000007
    for (int i = 2; i <= r; i++)
    {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }

    int ans = 1;

    // for 1/(r!) part
    for (int i = 2; i <= r; i++)
    {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }

    // for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for (int i = n; i >= (n - r + 1); i--)
    {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}

/* Driver code*/
int main()
{
    int n = 5, r = 2;
    cout << "Value of C(" << n << ", " << r << ") is "
         << binomialCoeff(n, r) << endl;
    return 0;
}
