// Cho một mảng số nguyên dương khác biệt biểu thị thời gian qua lại của 'n' người. Những người 'n' này đang đứng ở một bên cầu. Cầu có thể chứa tối đa hai người cùng một lúc. Khi hai người qua cầu, họ phải di chuyển với tốc độ của người chậm hơn. Tìm thời gian tối thiểu để tất cả mọi người có thể qua cầu. Xem câu đố này để hiểu thêm.

// Lưu ý: Không gian người chậm hơn được cung cấp bởi thời gian lớn hơn.

// Đầu vào: Thời gian giao nhau = {10, 20, 30}

// Đầu ra: 60

// Giải trình

// 1. Đầu tiên người '1' và '2' qua cầu

// với tổng thời gian khoảng 20 phút (tối đa là 10, 20)

// 2. Bây giờ người '1' sẽ quay lại với tổng số

// thời gian '10' phút.

// 3. Cuối cùng người '1' và '3' qua cầu

// với tổng thời gian khoảng 30 phút

// Vậy tổng thời gian đi cả chặng đường sẽ là

// 20 + 10 + 30 = 60

// Đầu vào: Thời gian giao nhau = [1, 2, 5, 8}

// Đầu ra: 15

// Giải trình

// Xem phần này để được giải thích đầy đủ.

// Cách tiếp cận là sử dụng lập trình Động. Trước khi đi sâu vào lập trình động, chúng ta hãy xem quan sát sau đây sẽ cần thiết để giải quyết vấn đề.

// Khi có hai người bất kỳ qua cầu thì thời gian qua cầu của người nhanh nhất sẽ không được tính vào đáp án vì cả hai đều di chuyển với tốc độ người chậm nhất.

// Khi một số người qua sông và đến được phía bên phải thì chỉ những người nhanh nhất (số nguyên nhỏ nhất) mới quay lại phía bên trái.

// Người chỉ có thể có mặt ở bên trái hoặc bên phải của cây cầu. Do đó, nếu chúng ta duy trì mặt nạ bên trái thì có thể dễ dàng tính toán mặt nạ bên phải bằng cách đặt các bit '1' không có trong mặt nạ bên trái. Ví dụ: Right_mask = ((2n) – 1) XOR (left_mask).

// Bất kỳ người nào cũng có thể dễ dàng được đại diện bởi bitmask (thường được gọi là 'mặt nạ'). Khi bit thứ i của 'mặt nạ' được đặt, điều đó có nghĩa là người đó hiện diện ở bên trái cầu, nếu không thì người đó sẽ hiện diện ở bên phải cầu. Ví dụ: giả sử mặt nạ của 6 người là 100101, đại diện cho người 1, 4, 6 có mặt ở bên trái cầu và người 2, 3 và 5 có mặt ở bên phải cầu.

// C++ program to find minimum time required to
// send people on other side of bridge
#include <bits/stdc++.h>
using namespace std;

/* Global dp[2^20][2] array, in dp[i][j]--
'i' denotes mask in which 'set bits' denotes
total people standing at left side of bridge
and 'j' denotes the turn that represent on
which side we have to send people either
from left to right(0) or from right to
left(1) */
int dp[1 << 20][2];

/* Utility function to find total time required
to send people to other side of bridge */
int findMinTime(int leftmask, bool turn, int arr[], int &n)
{

    // If all people has been transferred
    if (!leftmask)
        return 0;

    int &res = dp[leftmask][turn];

    // If we already have solved this subproblem,
    // return the answer.
    if (~res)
        return res;

    // Calculate mask of right side of people
    int rightmask = ((1 << n) - 1) ^ leftmask;

    /* if turn == 1 means currently people are at
    right side, thus we need to transfer
    people to the left side */
    if (turn == 1)
    {
        int minRow = INT_MAX, person;
        for (int i = 0; i < n; ++i)
        {

            // Select one people whose time is less
            // among all others present at right
            // side
            if (rightmask & (1 << i))
            {
                if (minRow > arr[i])
                {
                    person = i;
                    minRow = arr[i];
                }
            }
        }

        // Add that person to answer and recurse for next
        // turn after initializing that person at left side
        res = arr[person] + findMinTime(leftmask | (1 << person),
                                        turn ^ 1, arr, n);
    }
    else
    {

        // __builtin_popcount() is inbuilt gcc function
        // which will count total set bits in 'leftmask'
        if (__builtin_popcount(leftmask) == 1)
        {
            for (int i = 0; i < n; ++i)
            {

                // Since one person is present at left
                // side, thus return that person only
                if (leftmask & (1 << i))
                {
                    res = arr[i];
                    break;
                }
            }
        }
        else
        {

            // try for every pair of people by
            // sending them to right side

            // Initialize the result with maximum value
            res = INT_MAX;
            for (int i = 0; i < n; ++i)
            {

                // If ith person is not present then
                // skip the rest loop
                if (!(leftmask & (1 << i)))
                    continue;

                for (int j = i + 1; j < n; ++j)
                {
                    if (leftmask & (1 << j))
                    {

                        // Find maximum integer(slowest
                        // person's time)
                        int val = max(arr[i], arr[j]);

                        // Recurse for other people after
                        // un-setting the ith and jth bit of
                        // left-mask
                        val += findMinTime(
                            leftmask ^ (1 << i) ^ (1 << j),
                            turn ^ 1, arr, n);
                        // Find minimum answer among
                        // all chosen values
                        res = min(res, val);
                    }
                }
            }
        }
    }
    return res;
}

// Utility function to find minimum time
int findTime(int arr[], int n)
{
    // Find the mask of 'n' peoples
    int mask = (1 << n) - 1;

    // Initialize all entries in dp as -1
    memset(dp, -1, sizeof(dp));

    return findMinTime(mask, 0, arr, n);
}

// Driver program
int main()
{
    int arr[] = {10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findTime(arr, n);
    return 0;
}
