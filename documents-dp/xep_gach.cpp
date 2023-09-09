// Một tháp ổn định có chiều cao n là một tháp bao gồm chính xác n ô có chiều cao đơn vị xếp chồng lên nhau theo chiều dọc sao cho không có ô lớn hơn nào được đặt trên ô nhỏ hơn.

// Một ví dụ đã được biểu diễn ở dưới :

// Ta có vô số viên gạch có kích thước 1, 2, …, m. Nhiệm vụ là tính toán số lượng tháp ổn định khác nhau có chiều cao n có thể được xây dựng từ những ô này, với một hạn chế là bạn có thể sử dụng tối đa k ô ở mỗi kích thước trong tháp.

// Lưu ý: Hai tòa tháp có chiều cao n khác nhau khi và chỉ khi tồn tại độ cao h (1 <= h <= n), sao cho các tòa tháp có các viên gạch có kích thước khác nhau ở độ cao h.

// Ví dụ:

// Đầu vào: n = 3, m = 3, k = 1.

// Đầu ra: 1

// Các chuỗi có thể có: { 1, 2, 3}.

// Do đó đáp án là 1.

// Đầu vào: n = 3, m = 3, k = 2.

// Đầu ra: 7

// {1, 1, 2}, {1, 1, 3}, {1, 2, 2},

// {1, 2, 3}, {1, 3, 3}, {2, 2, 3},

// {2, 3, 3}.

// CPP program to find number of ways to make stable
// tower of given height.
#include <bits/stdc++.h>
using namespace std;
#define N 100

int possibleWays(int n, int m, int k)
{
    int dp[N][N];
    int presum[N][N];
    memset(dp, 0, sizeof dp);
    memset(presum, 0, sizeof presum);

    // Initializing 0th row to 0.
    for (int i = 1; i < n + 1; i++)
    {
        dp[0][i] = 0;
        presum[0][i] = 1;
    }

    // Initializing 0th column to 0.
    for (int i = 0; i < m + 1; i++)
        presum[i][0] = dp[i][0] = 1;

    // For each row from 1 to m
    for (int i = 1; i < m + 1; i++)
    {

        // For each column from 1 to n.
        for (int j = 1; j < n + 1; j++)
        {

            // Initializing dp[i][j] to presum of (i - 1, j).
            dp[i][j] = presum[i - 1][j];
            if (j > k)
            {
                dp[i][j] -= presum[i - 1][j - k - 1];
            }
        }

        // Calculating presum for each i, 1 <= i <= n.
        for (int j = 1; j < n + 1; j++)
            presum[i][j] = dp[i][j] + presum[i][j - 1];
    }

    return dp[m][n];
}

// Driver Program
int main()
{
    int n = 3, m = 3, k = 2;
    cout << possibleWays(n, m, k) << endl;
    return 0;
}
