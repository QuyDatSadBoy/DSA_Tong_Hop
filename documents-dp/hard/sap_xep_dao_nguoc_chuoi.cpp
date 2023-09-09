// Cho một mảng các chuỗi và chi phí đảo ngược tất cả các chuỗi, chúng ta cần sắp xếp mảng đó. Chúng ta không thể di chuyển các chuỗi trong mảng, chỉ cho phép đảo ngược chuỗi. Chúng ta cần đảo ngược một số chuỗi sao cho tất cả các chuỗi đều có thứ tự từ điển và chi phí cũng được giảm thiểu. Nếu không thể sắp xếp chuỗi theo bất kỳ cách nào thì không thể xuất ra.

// Ví dụ:

// Đầu vào : mảng[] = {�”, �”, �”},

// ReverseCost[] = {1, 3, 1}

// Đầu ra: Chi phí phân loại tối thiểu = 1

// Giải thích: Chúng ta có thể sắp xếp mảng chuỗi trên

// bằng cách đảo ngược một trong chuỗi thứ 2 hoặc thứ 3, nhưng đảo ngược

// Chuỗi thứ 2 có giá 3, vì vậy chúng tôi sẽ đảo ngược chuỗi thứ 3 thành

// tạo mảng chuỗi được sắp xếp với chi phí 1

// tối thiểu.

// Chúng ta có thể giải quyết vấn đề này bằng cách sử dụng quy hoạch động. Chúng tôi tạo một mảng 2D để lưu trữ chi phí sắp xếp tối thiểu.

// dp[i][j] thể hiện chi phí tối thiểu để thực hiện lần đầu tiên

// chuỗi được sắp xếp.

// j = 1 có nghĩa là chuỗi thứ i bị đảo ngược.

// j = 0 có nghĩa là chuỗi thứ i không bị đảo ngược.

// Giá trị của dp[i][j] được tính bằng dp[i-1][1] và

// dp[i-1][0].

// Tính toán dp[i][0]

// Nếu arr[i] lớn hơn str[i-1], chúng tôi cập nhật dp[i][0]

// bởi dp[i-1][0]

// Nếu arr[i] lớn hơn đảo ngược của chuỗi trước đó

// chúng tôi cập nhật dp[i][0] bởi dp[i-1][1]

// Quy trình tương tự được áp dụng để tính dp[i][1], chúng ta

// đảo ngược str[i] trước khi áp dụng quy trình.

// Cuối cùng, chúng tôi sẽ chọn tối thiểu dp[N-1][0] và

// dp[N-1][1] là câu trả lời cuối cùng của chúng tôi nếu cả hai đều không

// được cập nhật dù chỉ một lần, chúng tôi sẽ gắn cờ rằng việc sắp xếp đó là

// không thể.

// Dưới đây là cách thực hiện ý tưởng trên.

// C++ program to get minimum cost to sort
// strings by reversal operation
#include <bits/stdc++.h>
using namespace std;

// Returns minimum cost for sorting arr[]
// using reverse operation. This function
// returns -1 if it is not possible to sort.
int minCost(string arr[], int cost[], int N)
{
    // dp[i][j] represents the minimum cost to
    // make first i strings sorted.
    // j = 1 means i'th string is reversed.
    // j = 0 means i'th string is not reversed.
    int dp[N][2];

    // initializing dp array for first string
    dp[0][0] = 0;
    dp[0][1] = cost[0];

    // getting array of reversed strings
    string revStr[N];
    for (int i = 0; i < N; i++)
    {
        revStr[i] = arr[i];
        reverse(revStr[i].begin(), revStr[i].end());
    }

    string curStr;
    int curCost;

    // looping for all strings
    for (int i = 1; i < N; i++)
    {
        // Looping twice, once for string and once
        // for reversed string
        for (int j = 0; j < 2; j++)
        {
            dp[i][j] = INT_MAX;

            // getting current string and current
            // cost according to j
            curStr = (j == 0) ? arr[i] : revStr[i];
            curCost = (j == 0) ? 0 : cost[i];

            // Update dp value only if current string
            // is lexicographically larger
            if (curStr >= arr[i - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][0] + curCost);
            if (curStr >= revStr[i - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][1] + curCost);
        }
    }

    // getting minimum from both entries of last index
    int res = min(dp[N - 1][0], dp[N - 1][1]);

    return (res == INT_MAX) ? -1 : res;
}

// Driver code to test above methods
int main()
{
    string arr[] = {"aa", "ba", "ac"};
    int cost[] = {1, 3, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    int res = minCost(arr, cost, N);
    if (res == -1)
        cout << "Sorting not possible\n";
    else
        cout << "Minimum cost to sort strings is "
             << res;
}

#include <bits/stdc++.h>
using namespace std;

// Returns minimum cost for sorting arr[]
// using reverse operation. This function
// returns -1 if it is not possible to sort.
int minCost(string arr[], int cost[], int N)
{
    int dp0 = 0;       // Minimum cost for the previous string in original order
    int dp1 = cost[0]; // Minimum cost for the previous string in reversed order

    for (int i = 1; i < N; i++)
    {
        int cur0 = INT_MAX; // Minimum cost for the current string in original order
        int cur1 = INT_MAX; // Minimum cost for the current string in reversed order

        // Update dp values only if the current string is lexicographically larger
        if (arr[i] >= arr[i - 1])
            cur0 = min(cur0, dp0);
        if (arr[i] >= string(arr[i - 1].rbegin(), arr[i - 1].rend()))
            cur0 = min(cur0, dp1);

        // Update dp values for reversed strings
        if (string(arr[i].rbegin(), arr[i].rend()) >= arr[i - 1])
            cur1 = min(cur1, dp0 + cost[i]);
        if (string(arr[i].rbegin(), arr[i].rend()) >= string(arr[i - 1].rbegin(), arr[i - 1].rend()))
            cur1 = min(cur1, dp1 + cost[i]);

        dp0 = cur0; // Update the minimum cost for the previous string in original order
        dp1 = cur1; // Update the minimum cost for the previous string in reversed order
    }

    // Get the minimum from both entries of the last index
    int res = min(dp0, dp1);

    return (res == INT_MAX) ? -1 : res;
}

// Driver code to test above methods
int main()
{
    string arr[] = {"aa", "ba", "ac"};
    int cost[] = {1, 3, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    int res = minCost(arr, cost, N);
    if (res == -1)
        cout << "Sorting not possible\n";
    else
        cout << "Minimum cost to sort strings is " << res;

    return 0;
}
