// Cho một lưới có kích thước m * n, giả sử bạn đang bắt đầu tại (1, 1) và mục tiêu của bạn là đạt được (m, n).
// Trong mọi trường hợp, nếu bạn đang ở trên (x, y), bạn có thể đi tới (x, y + 1) hoặc (x + 1, y).

// Bây giờ hãy xem xét liệu một số chướng ngại vật có được thêm vào lưới hay không. Sẽ có bao nhiêu con đường duy
// nhất?

// Một chướng ngại vật và khoảng trống được đánh dấu lần lượt là 1 và 0 trong lưới.

// Ví dụ:

// Đầu vào: [[0, 0, 0],

// [0, 1, 0],

// [0, 0, 0]]

// Đầu ra: 2

// Chỉ có một trở ngại ở giữa.

// C++ code to find number of unique paths
// in a Matrix
#include <bits/stdc++.h>
using namespace std;

int UniquePathHelper(int i, int j, int r, int c,
                     vector<vector<int>> &A,
                     vector<vector<int>> &paths)
{
    // boundary condition or constraints
    if (i == r || j == c)
    {
        return 0;
    }

    if (A[i][j] == 1)
    {
        return 0;
    }

    // base case
    if (i == r - 1 && j == c - 1)
    {
        return 1;
    }

    if (paths[i][j] != -1)
    {
        return paths[i][j];
    }

    return paths[i][j] = UniquePathHelper(i + 1, j, r, c, A, paths) + UniquePathHelper(i, j + 1, r, c, A, paths);
}

int uniquePathsWithObstacles(vector<vector<int>> &A)
{

    int r = A.size(), c = A[0].size();

    // create a 2D-matrix and initializing
    // with value 0

    vector<vector<int>> paths(r, vector<int>(c, -1));

    return UniquePathHelper(0, 0, r, c, A, paths);
}

// Driver code
int main()
{
    vector<vector<int>> A = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << uniquePathsWithObstacles(A) << " \n";
}

// C++ code to find number of unique paths
// in a Matrix
#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &A)
{

    int r = A.size(), c = A[0].size();

    // create a 2D-matrix and initializing
    // with value 0
    vector<vector<int>> paths(r, vector<int>(c, 0));

    // Initializing the left corner if
    // no obstacle there
    if (A[0][0] == 0)
        paths[0][0] = 1;

    // Initializing first column of
    // the 2D matrix
    for (int i = 1; i < r; i++)
    {
        // If not obstacle
        if (A[i][0] == 0)
            paths[i][0] = paths[i - 1][0];
    }

    // Initializing first row of the 2D matrix
    for (int j = 1; j < c; j++)
    {

        // If not obstacle
        if (A[0][j] == 0)
            paths[0][j] = paths[0][j - 1];
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {

            // If current cell is not obstacle
            if (A[i][j] == 0)
                paths[i][j] = paths[i - 1][j] +
                              paths[i][j - 1];
        }
    }

    // Returning the corner value
    // of the matrix
    return paths[r - 1];
}

// Driver code
int main()
{
    vector<vector<int>> A = {{0, 0, 0},
                             {0, 1, 0},
                             {0, 0, 0}};

    cout << uniquePathsWithObstacles(A) << " \n";
}

// This code is contributed by ajaykr00kj

// CPP program for the above approach

#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &A)
{

    int r = A.size();
    int c = A[0].size();

    // If obstacle is at starting position
    if (A[0][0])
        return 0;

    // Initializing starting position
    A[0][0] = 1;

    // first row all are '1' until obstacle
    for (int j = 1; j < c; j++)
    {

        if (A[0][j] == 0)
        {
            A[0][j] = A[0][j - 1];
        }
        else
        {
            // No ways to reach at this index
            A[0][j] = 0;
        }
    }

    // first column all are '1' until obstacle
    for (int i = 1; i < r; i++)
    {

        if (A[i][0] == 0)
        {
            A[i][0] = A[i - 1][0];
        }
        else
        {
            // No ways to reach at this index
            A[i][0] = 0;
        }
    }

    for (int i = 1; i < r; i++)
    {

        for (int j = 1; j < c; j++)
        {
            // If current cell has no obstacle
            if (A[i][j] == 0)
            {

                A[i][j] = A[i - 1][j] + A[i][j - 1];
            }
            else
            {
                // No ways to reach at this index
                A[i][j] = 0;
            }
        }
    }

    // returning the bottom right
    // corner of Grid
    return A[r - 1];
}

// Driver Code

int main()
{

    vector<vector<int>> A = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << uniquePathsWithObstacles(A) << "\n";

    return 0;
}
// This code is contributed by hemantraj712

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int path(vector<vector<int>> &dp,
         vector<vector<int>> &grid, int i, int j)
{
    if (i < n && j < m && grid[i][j] == 1)
        return 0;
    if (i == n - 1 && j == m - 1)
        return 1;
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int left = path(dp, grid, i + 1, j);
    int right = path(dp, grid, i, j + 1);
    return dp[i][j] = left + right;
}
int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    if (n == 1 && m == 1 && grid[0][0] == 0)
        return 1;
    if (n == 1 && m == 1 && grid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // for(auto it:dp){
    //	 for(auto vt:it)cout<<vt<<" ";
    //	 cout<<endl;
    // }
    path(dp, grid, 0, 0);
    // for(auto it:dp){
    //	 for(auto vt:it)cout<<vt<<" ";
    //	 cout<<endl;
    // }
    if (dp[0][0] == -1)
        return 0;
    return dp[0][0];
}
// Driver Code
signed main()
{
    vector<vector<int>> v{{0, 0, 0},
                          {0, 1, 0},
                          {0, 0, 0}};
    cout << uniquePathsWithObstacles(v) << " \n";
    return 0;
}
