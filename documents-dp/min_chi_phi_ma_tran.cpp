// Cho ma trận chi phí cost[][] và vị trí (M, N) trong cost[][], hãy viết hàm trả về chi phí của đường dẫn chi phí
//  tối thiểu để đạt (M, N) từ (0, 0). Mỗi ô của ma trận biểu thị một chi phí để duyệt qua ô đó. Tổng chi phí của một đường đi tới
//   (M, N) là tổng của tất cả chi phí trên đường đi đó (bao gồm cả nguồn và đích). Bạn chỉ có thể duyệt xuống, sang phải và
//    theo đường chéo các ô thấp hơn từ một ô nhất định, tức là từ một ô nhất định (i, j), các ô (i+1, j), (i, j+1) và (i+1) , j+1)
//    có
//  thể đi qua.

// A Dynamic Programming based
// solution for MCP problem
#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int min(int x, int y, int z);

// Returns cost of minimum cost path
// from (0,0) to (m, n) in mat[R][C]
int minCostMemoized(int cost[R][C], int m, int n,
                    int memo[R][C])
{
    if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];

    if (memo[m][n] != -1)
        return memo[m][n];

    memo[m][n] = cost[m][n] + min(minCostMemoized(cost, m - 1, n - 1, memo),
                                  minCostMemoized(cost, m - 1, n, memo),
                                  minCostMemoized(cost, m, n - 1, memo));

    return memo[m][n];
}

// Returns cost of minimum cost path
// from (0,0) to (m, n) in mat[R][C]
int minCost(int cost[R][C], int m, int n)
{
    int memo[R][C];
    memset(memo, -1,
           sizeof(memo)); // Initialize memo table with -1

    return minCostMemoized(cost, m, n, memo);
}

// A utility function that returns
// minimum of 3 integers
int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

// Driver code
int main()
{
    int cost[R][C] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};

    cout << minCost(cost, 2, 2) << endl;

    return 0;
}

/* Dynamic Programming implementation of MCP problem */
#include <bits/stdc++.h>
#define R 3
#define C 3
using namespace std;

int min(int x, int y, int z);

int minCost(int cost[R][C], int m, int n)
{
    int i, j;

    // Instead of following line, we can use int
    // tc[m+1][n+1] or dynamically allocate memory to save
    // space. The following line is used to keep the program
    // simple and make it working on all compilers.
    int tc[R][C];

    tc[0][0] = cost[0][0];

    /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++)
        tc[i][0] = tc[i - 1][0] + cost[i][0];

    /* Initialize first row of tc array */
    for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j - 1] + cost[0][j];

    /* Construct rest of the tc array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i - 1][j - 1], tc[i - 1][j],
                           tc[i][j - 1]) +
                       cost[i][j];

    return tc[m][n];
}

/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

/* Driver code*/
int main()
{
    int cost[R][C] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    cout << " " << minCost(cost, 2, 2);
    return 0;
}

// This code is contributed by shivanisinghss2110

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

#define row 3
#define col 3

int minCost(int cost[row][col])
{

    // for 1st column
    for (int i = 1; i < row; i++)
        cost[i][0] += cost[i - 1][0];

    // for 1st row
    for (int j = 1; j < col; j++)
        cost[0][j] += cost[0][j - 1];

    // for rest of the 2d matrix
    for (int i = 1; i < row; i++)
        for (int j = 1; j < col; j++)
            cost[i][j] += min(cost[i - 1][j - 1],
                              min(cost[i - 1][j], cost[i][j - 1]));

    // returning the value in last cell
    return cost[row - 1][col - 1];
}

// Driver code
int main(int argc, char const *argv[])
{
    int cost[row][col] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};

    cout << minCost(cost) << endl;
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

/* Minimum Cost Path using Dijkstra’s shortest path
algorithm with Min Heap by dinglizeng */
#include <bits/stdc++.h>
using namespace std;

/* define the number of rows and the number of columns */
#define R 4
#define C 5

/* 8 possible moves */
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

/* The data structure to store the coordinates of \\
the unit square and the cost of path from the top left. */
struct Cell
{
    int x;
    int y;
    int cost;
};

/* The compare class to be used by a Min Heap.
* The greater than condition is used as this
is for a Min Heap based on priority_queue.
*/
class mycomparison
{
public:
    bool operator()(const Cell &lhs, const Cell &rhs) const
    {
        return (lhs.cost > rhs.cost);
    }
};

/* To verify whether a move is within the boundary. */
bool isSafe(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

/* This solution is based on Dijkstra’s shortest path
algorithm
* For each unit square being visited, we examine all
    possible next moves in 8 directions,
* calculate the accumulated cost of path for each
    next move, adjust the cost of path of the adjacent
    units to the minimum as needed.
* then add the valid next moves into a Min Heap.
* The Min Heap pops out the next move with the minimum
accumulated cost of path.
* Once the iteration reaches the last unit at the lower
right corner, the minimum cost path will be returned.
*/
int minCost(int cost[R][C], int m, int n)
{

    /* the array to store the accumulated cost
    of path from top left corner */
    int dp[R][C];

    /* the array to record whether a unit
    square has been visited */
    bool visited[R][C];

    /* Initialize these two arrays, set path cost
    to maximum integer value, each unit as not visited */
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            dp[i][j] = INT_MAX;
            visited[i][j] = false;
        }
    }

    /* Define a reverse priority queue.
    * Priority queue is a heap based implementation.
    * The default behavior of a priority queue is
        to have the maximum element at the top.
    * The compare class is used in the definition of the
    Min Heap.
    */
    priority_queue<Cell, vector<Cell>, mycomparison> pq;

    /* initialize the starting top left unit with the
    cost and add it to the queue as the first move. */
    dp[0][0] = cost[0][0];
    pq.push({0, 0, cost[0][0]});

    while (!pq.empty())
    {

        /* pop a move from the queue, ignore the units
        already visited */
        Cell cell = pq.top();
        pq.pop();
        int x = cell.x;
        int y = cell.y;
        if (visited[x][y])
            continue;

        /* mark the current unit as visited */
        visited[x][y] = true;

        /* examine all non-visited adjacent units in 8
        directions
        * calculate the accumulated cost of path for
        each next move from this unit,
        * adjust the cost of path for each next adjacent
        units to the minimum if possible.
        */
        for (int i = 0; i < 8; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (isSafe(next_x, next_y) && !visited[next_x][next_y])
            {
                dp[next_x][next_y] = min(dp[next_x][next_y],
                                         dp[x][y] + cost[next_x][next_y]);
                pq.push(
                    {next_x, next_y, dp[next_x][next_y]});
            }
        }
    }

    /* return the minimum cost path at the lower
    right corner */
    return dp[m][n];
}

/* Driver code */
int main()
{
    int cost[R][C] = {{1, 8, 8, 1, 5},
                      {4, 1, 1, 8, 1},
                      {4, 2, 8, 8, 1},
                      {1, 5, 8, 8, 1}};
    printf(" %d ", minCost(cost, 3, 4));
    return 0;
}
