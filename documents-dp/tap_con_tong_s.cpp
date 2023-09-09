// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output: True
// Explanation: There is a subset (4, 5) with sum 9.

// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
// Output: False
// Explanation: There is no subset that add up to 30.

// A recursive solution for subset sum problem

#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    // Else, check if sum can be obtained by any
    // of the following:
    // (a) including the last element
    // (b) excluding the last element
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Driver code
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}

// This code is contributed by shivanisinghss2110

// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Taking the matrix as globally
int tab[2000][2000];

// Check if possible subset with
// given sum is possible or not
int subsetSum(int a[], int n, int sum)
{
    // If the sum is zero it means
    // we got our expected sum
    if (sum == 0)
        return 1;

    if (n <= 0)
        return 0;

    // If the value is not -1 it means it
    // already call the function
    // with the same value.
    // it will save our from the repetition.
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];

    // If the value of a[n-1] is
    // greater than the sum.
    // we call for the next value
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else
    {
        // Here we do two calls because we
        // don't know which value is
        // full-fill our criteria
        // that's why we doing two calls
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
                                 subsetSum(a, n - 1, sum - a[n - 1]);
    }
}

// Driver Code
int main()
{
    // Storing the value -1 to the matrix
    memset(tab, -1, sizeof(tab));
    int n = 5;
    int a[] = {1, 5, 3, 7, 4};
    int sum = 12;

    if (subsetSum(a, n, sum))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    /* This Code is Contributed by Ankit Kumar*/
}

// A Dynamic Programming solution
// for subset sum problem
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

// Driver code
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}
// This code is contributed by shivanisinghss2110

// A Dynamic Programming solution
// for subset sum problem with space optimization
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{

    vector<bool> prev(sum + 1);

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        prev[0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        prev[i] = false;

    // curr array to store the current row result generated
    // with help of prev array
    vector<bool> curr(sum + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                curr[j] = prev[j];
            if (j >= set[i - 1])
                curr[j] = prev[j] || prev[j - set[i - 1]];
        }
        // now curr becomes prev for i+1 th element
        prev = curr;
    }

    return prev[sum];
}

// Driver code
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}
// This code is contributed by Hem Kishan
