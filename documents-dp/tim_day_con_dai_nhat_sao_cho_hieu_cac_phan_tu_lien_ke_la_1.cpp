// Cho một mảng có kích thước n, nhiệm vụ là tìm dãy con dài nhất sao cho hiệu giữa các phần liền kề là một.

// Ví dụ:

// Đầu vào: mảng[] = {10, 9, 4, 5, 4, 8, 6}

// Đầu ra: 3

// Vì các dãy con dài nhất có chênh lệch 1 là "10, 9, 8",

// "4, 5, 4" và "4, 5, 6"

// Đầu vào: mảng[] = {1, 2, 3, 2, 3, 7, 2, 1}

// Đầu ra: 7

// Chuỗi liên tiếp dài nhất là "1, 2, 3, 2, 3, 2, 1"

// Bài toán này dựa trên khái niệm Bài toán dãy con tăng dài nhất.

// Đặt arr[0..n-1] là mảng đầu vào và

// dp[i] là độ dài của dãy con dài nhất (với

// khác biệt một) kết thúc ở chỉ số i sao cho arr[i]

// là phần tử cuối cùng của dãy con.

// Khi đó, dp[i] có thể được viết đệ quy dưới dạng:

// dp[i] = 1 + max(dp[j]) trong đó 0 < j < i và

// [arr[j] = arr[i] -1 hoặc arr[j] = arr[i] + 1]

// dp[i] = 1, nếu không có j như vậy tồn tại.

// Để tìm kết quả của một mảng nhất định, chúng ta cần

// để trả về max(dp[i]) trong đó 0 < i < n.

// C++ program to find the longest subsequence such
// the difference between adjacent elements of the
// subsequence is one.
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of longest subsequence
int longestSubseqWithDiffOne(int arr[], int n)
{
    // Initialize the dp[] array with 1 as a
    // single element will be of 1 length
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    // Start traversing the given array
    for (int i = 1; i < n; i++)
    {
        // Compare with all the previous elements
        for (int j = 0; j < i; j++)
        {
            // If the element is consecutive then
            // consider this subsequence and update
            // dp[i] if required.
            if ((arr[i] == arr[j] + 1) || (arr[i] == arr[j] - 1))

                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    // Longest length will be the maximum value
    // of dp array.
    int result = 1;
    for (int i = 0; i < n; i++)
        if (result < dp[i])
            result = dp[i];
    return result;
}

// Driver code
int main()
{
    // Longest subsequence with one difference is
    // {1, 2, 3, 4, 3, 2}
    int arr[] = {1, 2, 3, 4, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestSubseqWithDiffOne(arr, n);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int longestSubsequence(int n, int arr[])
{
    if (n == 1)
        return 1;
    unordered_map<int, int> mapp;
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (mapp.count(arr[i] + 1) > 0 || mapp.count(arr[i] - 1) > 0)
        {
            mapp[arr[i]] = 1 + max(mapp[arr[i] + 1], mapp[arr[i] - 1]);
        }
        else
            mapp[arr[i]] = 1;
        res = max(res, mapp[arr[i]]);
    }
    return res;
    // This code is contributed by Akansha Mittal
}
int main()
{
    // Longest subsequence with one difference is
    // {1, 2, 3, 4, 3, 2}
    int arr[] = {1, 2, 3, 4, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestSubsequence(n, arr);
    return 0;
}
