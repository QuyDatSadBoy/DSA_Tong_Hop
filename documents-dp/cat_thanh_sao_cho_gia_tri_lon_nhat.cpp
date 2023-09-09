// Cho một thanh có chiều dài n inch và một dãy giá bao gồm giá của tất cả các mảnh có kích thước nhỏ hơn n. Xác định giá trị lớn nhất có thể đạt được bằng cách cắt thanh và bán các mảnh đó. Ví dụ: nếu chiều dài của thanh là 8 và giá trị của các mảnh khác nhau được cho như sau thì giá trị tối đa có thể đạt được là 22 (bằng cách cắt thành hai mảnh có chiều dài 2 và 6)

// chiều dài | 1 2 3 4 5 6 7 8

// --------------------------------------------

// giá | 1 5 8 9 10 17 17 20

// Và nếu giá như sau thì giá trị tối đa có thể đạt được là 24 (bằng cách cắt thành 8 đoạn có chiều dài 1)

// chiều dài | 1 2 3 4 5 6 7 8

// --------------------------------------------

// giá | 3 5 8 9 10 17 17 20

// Phương pháp 1: Một giải pháp đơn giản cho vấn đề này là tạo ra tất cả cấu hình của các phần khác nhau và tìm cấu hình có giá cao nhất. Giải pháp này là theo cấp số nhân về độ phức tạp thời gian. Chúng ta hãy xem làm thế nào vấn đề này sở hữu cả hai tính chất quan trọng của Bài toán quy hoạch động (DP) và có thể được giải quyết một cách hiệu quả bằng cách sử dụng Quy hoạch động.

// 1) Cấu trúc tối ưu:

// Chúng ta có thể có được mức giá tốt nhất bằng cách thực hiện cắt giảm ở các vị trí khác nhau và so sánh các giá trị thu được sau khi cắt. Chúng ta có thể gọi đệ quy hàm tương tự cho một phần thu được sau khi cắt.

// Đặt cutRod(n) là giá trị bắt buộc (giá tốt nhất có thể) cho một thanh có chiều dài n. cutRod(n) có thể được viết như sau.

// cutRod(n) = max(price[i] + cutRod(n-i-1)) với tất cả i trong {0, 1 .. n-1}

// A recursive solution for Rod cutting problem
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* Returns the best obtainable price for a rod of length n
and price[] as prices of different pieces */
int cutRod(int price[], int index, int n)
{
    // base case
    if (index == 0)
    {
        return n * price[0];
    }
    // At any index we have 2 options either
    // cut the rod of this length or not cut
    // it
    int notCut = cutRod(price, index - 1, n);
    int cut = INT_MIN;
    int rod_length = index + 1;

    if (rod_length <= n)
        cut = price[index] + cutRod(price, index, n - rod_length);

    return max(notCut, cut);
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Obtainable Value is "
         << cutRod(arr, size - 1, size);
    getchar();
    return 0;
}

// This code is contributed by Sanskar

// A memoization solution for Rod cutting problem
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* Returns the best obtainable price for a rod of length n
and price[] as prices of different pieces */
int cutRod(int price[], int index, int n,
           vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        return n * price[0];
    }
    if (dp[index][n] != -1)
        return dp[index][n];
    // At any index we have 2 options either
    // cut the rod of this length or not cut
    // it
    int notCut = cutRod(price, index - 1, n, dp);
    int cut = INT_MIN;
    int rod_length = index + 1;

    if (rod_length <= n)
        cut = price[index] + cutRod(price, index, n - rod_length, dp);

    return dp[index][n] = max(notCut, cut);
}
/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> dp(size,
                           vector<int>(size + 1, -1));
    cout << "Maximum Obtainable Value is "
         << cutRod(arr, size - 1, size, dp);
    getchar();
    return 0;
}

// This code is contributed by Sanskar

// A Dynamic Programming solution for Rod cutting problem
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* Returns the best obtainable price for a rod of length n and
price[] as prices of different pieces */
int cutRod(int price[], int n)
{
    int val[n + 1];
    val[0] = 0;
    int i, j;

    // Build the table val[] in bottom up manner and return the last entry
    // from the table
    for (i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (j = 0; j < i; j++)
            max_val = max(max_val, price[j] + val[i - j - 1]);
        val[i] = max_val;
    }

    return val[n];
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Obtainable Value is " << cutRod(arr, size);
    getchar();
    return 0;
}

// This code is contributed by shivanisinghss2110

// CPP program for above approach
#include <iostream>
using namespace std;

// Global Array for
// the purpose of memoization.
int t[9][9];

// A recursive program, using ,
// memoization, to implement the
// rod cutting problem(Top-Down).
int un_kp(int price[], int length[],
          int Max_len, int n)
{

    // The maximum price will be zero,
    // when either the length of the rod
    // is zero or price is zero.
    if (n == 0 || Max_len == 0)
    {
        return 0;
    }

    // If the length of the rod is less
    // than the maximum length, Max_lene will
    // consider it.Now depending
    // upon the profit,
    // either Max_lene we will take
    // it or discard it.
    if (length[n - 1] <= Max_len)
    {
        t[n][Max_len] = max(price[n - 1] + un_kp(price, length,
                                                 Max_len - length[n - 1], n),
                            un_kp(price, length, Max_len, n - 1));
    }

    // If the length of the rod is
    // greater than the permitted size,
    // Max_len we will not consider it.
    else
    {
        t[n][Max_len] = un_kp(price, length,
                              Max_len, n - 1);
    }

    // Max_lene Max_lenill return the maximum
    // value obtained, Max_lenhich is present
    // at the nth roMax_len and Max_length column.
    return t[n][Max_len];
}

/* Driver program to
test above functions */
int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }
    int Max_len = n;

    // Function Call
    cout << "Maximum obtained value is "
         << un_kp(price, length, n, Max_len) << endl;
}

#include <algorithm>
#include <iostream>
using namespace std;

int cutRod(int prices[], int n)
{
    int mat[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                mat[i][j] = 0;
            }
            else
            {
                if (i == 1)
                {
                    mat[i][j] = j * prices[i - 1];
                }
                else
                {
                    if (i > j)
                    {
                        mat[i][j] = mat[i - 1][j];
                    }
                    else
                    {
                        mat[i][j] = max(prices[i - 1] + mat[i][j - i],
                                        mat[i - 1][j]);
                    }
                }
            }
        }
    }

    return mat[n][n];
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "Maximum obtained value is "
         << cutRod(prices, n) << endl;
}
