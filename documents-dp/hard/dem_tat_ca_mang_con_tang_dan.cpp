// Cho một mảng gồm n số nguyên dương. Nhiệm vụ là đếm số dãy con Tiến trình số học trong mảng. Lưu ý: Chuỗi trống hoặc chuỗi phần tử đơn là Cấp số học. 1 <= mảng[i] <= 1000000.

// Ví dụ:

// Đầu vào: mảng[] = { 1, 2, 3 }

// Đầu ra: 8

// Chuỗi cấp tiến số học con từ

// mảng đã cho là: {}, { 1 }, { 2 }, { 3 }, { 1, 2 },

// {2, 3 }, { 1, 3 }, { 1, 2, 3 }.

// Đầu vào: mảng[] = { 10, 20, 30, 45 }

// Đầu ra: 12

// Đầu vào: mảng[] = { 1, 2, 3, 4, 5 }

// Đầu ra: 23

// Vì chuỗi trống và chuỗi phần tử đơn cũng là cấp số cộng nên chúng ta khởi tạo câu trả lời bằng n(số phần tử trong mảng) + 1.

// Bây giờ, chúng ta cần tìm dãy con cấp số cộng có độ dài lớn hơn hoặc bằng 2. Đặt giá trị tối thiểu và tối đa của mảng lần lượt là minarr và maxarr. Quan sát, trong tất cả các dãy con cấp số cộng, khoảng sai phân chung sẽ từ (minar – maxarr) đến (maxarr – minarr). Bây giờ, với mỗi hiệu chung, giả sử d, hãy tính dãy con có độ dài lớn hơn hoặc bằng 2 bằng cách sử dụng quy hoạch động.

// Gọi dp[i] là số dãy con kết thúc bằng arr[i] và có hiệu chung là d. Vì thế,

// Số dãy con có độ dài lớn hơn hoặc bằng 2 có sai phân chung d là tổng của dp[i] – 1, 0 <= i = 2 có hiệu d. Để tăng tốc, hãy lưu tổng của dp[j] với arr[j] + d = arr[i] và j < i.

// Dưới đây là cách thực hiện ý tưởng trên:

// C++ program to find number of AP
// subsequences in the given array
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int numofAP(int a[], int n)
{
    // initializing the minimum value and
    // maximum value of the array.
    int minarr = INT_MAX, maxarr = INT_MIN;

    // Finding the minimum and maximum
    // value of the array.
    for (int i = 0; i < n; i++)
    {
        minarr = min(minarr, a[i]);
        maxarr = max(maxarr, a[i]);
    }

    // dp[i] is going to store count of APs ending
    // with arr[i].
    // sum[j] is going to store sum of all dp[]'s
    // with j as an AP element.
    int dp[n], sum[MAX];

    // Initialize answer with n + 1 as single elements
    // and empty array are also DP.
    int ans = n + 1;

    // Traversing with all common difference.
    for (int d = (minarr - maxarr); d <= (maxarr - minarr); d++)
    {
        memset(sum, 0, sizeof sum);

        // Traversing all the element of the array.
        for (int i = 0; i < n; i++)
        {
            // Initialize dp[i] = 1.
            dp[i] = 1;

            // Adding counts of APs with given differences
            // and a[i] is last element.
            // We consider all APs where an array element
            // is previous element of AP with a particular
            // difference
            if (a[i] - d >= 1 && a[i] - d <= 1000000)
                dp[i] += sum[a[i] - d];

            ans += dp[i] - 1;
            sum[a[i]] += dp[i];
        }
    }

    return ans;
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << numofAP(arr, n) << endl;
    return 0;
}
