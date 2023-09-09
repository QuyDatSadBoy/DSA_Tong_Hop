#include <bits/stdc++.h>
using namespace std;

void maxMatrixSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // no of rows in a matrix;
    int m = matrix[0].size(); // no of columns in matrix;
    int maxsum = INT_MIN;
    int top = 0, bottom = 0, left = 0, right = 0;
    // a loop for top row position in  the
    // rectangle
    for (int i = 0; i < n; i++)
    {
        // a loop for  left column position
        // of the rectangle
        for (int j = 0; j < m; j++)
        {
            // a loop for bottom  row in the
            // rectangle
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    // a loop for right column in
                    // the rectangle
                    int curr = 0;
                    for (int x = i; x <= k; x++)
                    {
                        // a loops execute for
                        // finding sum of elements in the
                        // rectangle
                        for (int y = j; y <= l; y++)
                        {
                            // for all possibble
                            // points of rectangle
                            curr += matrix[x][y];
                        }
                    }
                    // updating the resultant variables if curr > maxsum
                    if (curr > maxsum)
                    {
                        maxsum = curr;
                        top = i;
                        left = j;
                        right = k;
                        bottom = l;
                    }
                }
            }
        }
    }
    cout << "( Top , Left )"
         << "( " << top << " , " << left << " )" << endl;
    cout << "( Bottom , Right )"
         << "( " << bottom << " , " << right << " )"
         << endl;
    cout << "The sum of this rectangle is: " << maxsum
         << endl;
}
int main()
{
    vector<vector<int>> v = {{1, 2, -1, -4, -20},
                             {-8, -3, 4, 2, 1},
                             {3, 8, 10, 1, 3},
                             {-4, -1, 1, 7, -6}};
    maxMatrixSum(v);
    return 0;
}
// // contributed by hungry_coder_109(Naveen);
// Output:
// ( Top , Left )( 1 , 1 )

// ( Bottom , Right )( 3 , 3 )

// The sum of this rectangle is: 29

// Time Complexity: O(n^3 * m^3) where n is the number of rows and m is the numbr of columns in the given matrix.

// Program to find maximum sum subarray
// in a given 2D array
#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

// Implementation of Kadane's algorithm for
// 1D array. The function returns the maximum
// sum and stores starting and ending indexes
// of the maximum sum subarray at addresses
// pointed by start and finish pointers
// respectively.
int kadane(int *arr, int *start, int *finish, int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check
    // for all negative values case
    *finish = -1;

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    // There is at-least one
    // non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers
    // in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

// The main function that finds
// maximum sum rectangle in M[][]
void findMaxSum(int M[][COL])
{
    // Variables to store the final output
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop,
        finalBottom;

    int left, right, i;
    int temp[ROW], sum, start, finish;

    // Set the left column
    for (left = 0; left < COL; ++left)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left
        // column set by outer loop
        for (right = left; right < COL; ++right)
        {

            // Calculate sum between current left
            // and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            // Find the maximum sum subarray in temp[].
            // The kadane() function also sets values
            // of start and finish. So 'sum' is sum of
            // rectangle between (start, left) and
            // (finish, right) which is the maximum sum
            // with boundary columns strictly as left
            // and right.
            sum = kadane(temp, &start, &finish, ROW);

            // Compare sum with maximum sum so far.
            // If sum is more, then update maxSum and
            // other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    // Print final values
    cout << "(Top, Left) (" << finalTop << ", " << finalLeft
         << ")" << endl;
    cout << "(Bottom, Right) (" << finalBottom << ", "
         << finalRight << ")" << endl;
    cout << "Max sum is: " << maxSum << endl;
}

// Driver Code
int main()
{
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}};

    // Function call
    findMaxSum(M);

    return 0;
}

// This code is contributed by
// rathbhupendra
