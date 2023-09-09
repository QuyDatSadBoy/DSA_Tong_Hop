// Trong giao dịch cổ phiếu, người mua mua cổ phiếu và bán vào một ngày trong tương lai. Với giá cổ phiếu là n ngày, người giao dịch được phép thực hiện tối đa k giao dịch, trong đó giao dịch mới chỉ có thể bắt đầu sau khi giao dịch trước đó hoàn tất, tìm ra lợi nhuận tối đa mà người giao dịch cổ phiếu có thể kiếm được.

// Ví dụ:

// Đầu vào:

// Giá = [10, 22, 5, 75, 65, 80]

// K = 2

// Đầu ra: 87

// Nhà giao dịch kiếm được 87 bằng tổng của 12 và 75

// Mua ở giá 10, bán ở giá 22, mua ở giá

// 5 và bán với giá 80

// Đầu vào:

// Giá = [12, 14, 17, 10, 14, 13, 12, 15]

// K = 3

// Đầu ra: 12

// Nhà giao dịch kiếm được 12 bằng tổng của 5, 4 và 3

// Mua giá 12, bán giá 17, mua giá 10

// và bán ở giá 14 và mua ở giá 12 và bán

// lúc 15 tuổi

// Đầu vào:

// Giá = [100, 30, 15, 10, 8, 25, 80]

// K = 3

// Đầu ra: 72

// Chỉ có một giao dịch. Mua với giá 8

// và bán với giá 80.

// Đầu vào:

// Giá = [90, 80, 70, 60, 50]

// K = 1

// Đầu ra: 0

// Không thể kiếm được.

// Có nhiều phiên bản khác nhau của vấn đề. Nếu chúng ta chỉ được phép mua và bán một lần thì chúng ta có thể sử dụng thuật toán Chênh lệch tối đa giữa hai phần tử. Nếu chúng tôi được phép thực hiện tối đa 2 giao dịch, chúng tôi có thể thực hiện theo cách tiếp cận được thảo luận ở đây. Nếu chúng ta được phép mua và bán bất kỳ số lần nào, chúng ta có thể làm theo cách tiếp cận được thảo luận ở đây.

// Phương pháp 1 Lập trình động

// Trong bài đăng này, chúng tôi chỉ được phép thực hiện tối đa k giao dịch. Vấn đề có thể được giải quyết bằng cách sử dụng quy hoạch động.

// Đặt lợi nhuận[t][i] đại diện cho lợi nhuận tối đa khi sử dụng tối đa t giao dịch cho đến ngày thứ i (bao gồm cả ngày thứ i). Khi đó mối quan hệ là:

// lợi nhuận[t][i] = max(lợi nhuận[t][i-1], max(giá[i] – giá[j] + lợi nhuận[t-1][j]))

// cho tất cả j trong phạm vi [0, i-1]

// lợi nhuận[t][i] sẽ tối đa là –

// lợi nhuận[t] [i-1] thể hiện việc không thực hiện bất kỳ giao dịch nào vào ngày thứ i.

// Lợi nhuận tối đa thu được khi bán vào ngày thứ i. Để bán cổ phiếu vào ngày thứ i, chúng ta cần mua nó vào một trong [0, i – 1] ngày bất kỳ. Nếu chúng ta mua cổ phiếu vào ngày thứ j và bán nó vào ngày thứ i, lợi nhuận tối đa sẽ là giá[i] – giá[j] + lợi nhuận[t-1][j] trong đó j thay đổi từ 0 đến i-1. Ở đây lợi nhuận[t-1][j] là mức tốt nhất mà chúng ta có thể thực hiện được với ít giao dịch hơn cho đến ngày thứ j.

// Dưới đây là triển khai dựa trên Lập trình động

// C++ program to find out maximum profit by
// buying and selling a share atmost k times
// given stock price of n days
#include <climits>
#include <iostream>
using namespace std;

// Function to find out maximum profit by buying
// & selling a share atmost k times given stock
// price of n days
int maxProfit(int price[], int n, int k)
{
    // table to store results of subproblems
    // profit[t][i] stores maximum profit using
    // atmost t transactions up to day i (including
    // day i)
    int profit[k + 1][n + 1];

    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;

    // profit is 0 if we don't do any transaction
    // (i.e. k =0)
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;

    // fill the table in bottom-up fashion
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int max_so_far = INT_MIN;

            for (int m = 0; m < j; m++)
                max_so_far = max(max_so_far,
                                 price[j] - price[m] + profit[i - 1][m]);

            profit[i][j] = max(profit[i][j - 1], max_so_far);
        }
    }

    return profit[k][n - 1];
}

// Driver code
int main()
{
    int k = 2;
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum profit is: "
         << maxProfit(price, n, k);

    return 0;
}

// C++ program to find out maximum profit by buying
// and/ selling a share atmost k times given stock
// price of n days
#include <climits>
#include <iostream>
using namespace std;

// Function to find out maximum profit by buying &
// selling/ a share atmost k times given stock price
// of n days
int maxProfit(int price[], int n, int k)
{
    // table to store results of subproblems
    // profit[t][i] stores maximum profit using atmost
    // t transactions up to day i (including day i)
    int profit[k + 1][n + 1];

    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;

    // profit is 0 if we don't do any transaction
    // (i.e. k =0)
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;

    // fill the table in bottom-up fashion
    for (int i = 1; i <= k; i++)
    {
        int prevDiff = INT_MIN;
        for (int j = 1; j < n; j++)
        {
            prevDiff = max(prevDiff,
                           profit[i - 1][j - 1] - price[j - 1]);
            profit[i][j] = max(profit[i][j - 1],
                               price[j] + prevDiff);
        }
    }

    return profit[k][n - 1];
}

// Driver Code
int main()
{
    int k = 3;
    int price[] = {12, 14, 17, 10, 14, 13, 12, 15};

    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum profit is: "
         << maxProfit(price, n, k);

    return 0;
}

// C++ program to find out maximum profit by
// buying and selling a share atmost k times
// given stock price of n days
#include <bits/stdc++.h>
using namespace std;

int B;
vector<int> A;
int dp[501][201][2];
int solve(int j, int i, int b)
{
    // if the result has already been calculated return that result
    if (dp[i][j][b] != -1)
        return dp[i][j][b];
    // if i has reached the end of the array return 0
    if (i == B)
        return 0;
    // if we have exhausted the number of transaction return 0
    if (j == 0)
        return 0;
    int res;
    // if we are to buy stocks
    if (b == 1)
        res = max(-A[i] + solve(j, i + 1, 0), solve(j, i + 1, 1));
    // if we are to sell stock and complete one transaction
    else
        res = max(A[i] + solve(j - 1, i + 1, 1), solve(j, i + 1, 0));
    // return the result
    return dp[i][j][b] = res;
}
int maxProfit(int K, int N, int C[])
{
    A = vector<int>(N, 0);
    // Copying C to global A
    for (int i = 0; i < N; i++)
        A[i] = C[i];
    // Initializing DP with -1
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
        {
            dp[i][j][1] = -1;
            dp[i][j][0] = -1;
        }
    // Copying n to global B
    B = N;
    return solve(K, 0, 1);
}

// driver code
int main()
{
    // TEST 1
    int k1 = 3;
    int price1[] = {12, 14, 17, 10, 14, 13, 12, 15};
    int n1 = sizeof(price1) / sizeof(price1[0]);
    cout << "Maximum profit is: "
         << maxProfit(k1, n1, price1) << endl;
    // TEST 2
    int k2 = 2;
    int price2[] = {10, 22, 5, 75, 65, 80};
    int n2 = sizeof(price2) / sizeof(price2[0]);

    cout << "Maximum profit is: "
         << maxProfit(k2, n2, price2);
    return 0;
}
// This code is contributed by Anirudh Singh

// C++ program to find out maximum profit by
// buying and selling a share atmost k times
// given stock price of n days
#include <climits>
#include <iostream>
using namespace std;

// Function to find out maximum profit by buying
// & selling a share atmost k times given stock
// price of n days
int f(int idx, int buy, int prices[], int cap, int n)
{
    if (cap == 0)
    {
        return 0;
    }

    if (idx == n)
    {
        return 0;
    }

    int profit = 0;
    // you can either buy or not buy
    if (buy == 0)
    {
        profit = max(-prices[idx] + f(idx + 1, 1, prices, cap, n),
                     f(idx + 1, 0, prices, cap, n));
    }
    // you can either sell or not sell
    else
    {
        profit = max(
            prices[idx] + f(idx + 1, 0, prices, cap - 1, n),
            f(idx + 1, 1, prices, cap, n));
    }

    return profit;
}

int maxProfit(int prices[], int n, int k)
{

    return f(0, 0, prices, k, n);
}

// Driver code
int main()
{
    int k = 2;
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum profit is: " << maxProfit(price, n, k);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to find out maximum profit by buying &
// selling a share at most k times given stock price
// of n days
int maxProfit(int price[], int n, int k)
{
    // vector to store results of subproblems
    // profit[i] stores maximum profit using at most
    // i transactions up to the current day
    vector<int> profit(k + 1, 0);
    vector<int> prevDiff(k + 1, INT_MIN);

    // fill the table in bottom-up fashion
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i <= k; i++)
        {
            prevDiff[i] = max(prevDiff[i], profit[i - 1] - price[j]);
            profit[i] = max(profit[i], price[j] + prevDiff[i]);
        }
    }

    return profit[k];
}

// Driver Code
int main()
{
    int k = 3;
    int price[] = {12, 14, 17, 10, 14, 13, 12, 15};

    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum profit is: "
         << maxProfit(price, n, k);

    return 0;
}

// -- by bhardwajji
