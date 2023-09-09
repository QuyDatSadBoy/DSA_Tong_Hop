// Cho N bảng có chiều dài mỗi bảng cho trước dưới dạng mảng và K họa sĩ, sao cho mỗi họa sĩ mất 1 đơn vị thời gian để vẽ 1 đơn vị bảng. Nhiệm vụ là tìm thời gian tối thiểu để vẽ tất cả các bảng với điều kiện là bất kỳ họa sĩ nào cũng sẽ chỉ vẽ các phần liên tục của bảng, ví dụ bảng {2, 3, 4} hoặc chỉ bảng {1} hoặc không vẽ gì ngoài bảng {2, 4 , 5}.

// Ví dụ:

// Đầu vào: N = 4, A = {10, 10, 10, 10}, K = 2

// Đầu ra: 20

// Giải thích: Ở đây chúng ta có thể chia các bảng thành 2 phân vùng có kích thước bằng nhau (Họa sĩ 1 sẽ sơn bảng A1 và A2, còn Họa sĩ 2 sẽ sơn bảng A3 và A4). Vậy mỗi họa sĩ nhận được 20 tấm ván và tổng thời gian thực hiện là 20.

// Đầu vào: N = 4, A = {10, 20, 30, 40}, K = 2

// Đầu ra: 60

// Giải thích: Vì chỉ có 2 họa sĩ nên chia 3 bảng đầu tiên cho họa sĩ 1 (A1, A2 và A3) với thời gian = 60, và chia 3 bảng cuối cùng cho họa sĩ 2 (A4) với thời gian = 40. Do đó tổng thời gian thực hiện = 60, đó là mức tối thiểu có thể.

// Vui lòng lưu ý kết hợp A1 và A4 với Họa sĩ 1 với thời gian 50, và A2 và A3 với Họa sĩ 2 với thời gian 50, sẽ mang lại thời gian nhỏ hơn (50 đơn vị). Nhưng điều này không thể được xem xét do hạn chế là người họa sĩ không thể vẽ những loạt bảng không liên tục.

// Đề nghị thực hành

// Bài toán phân vùng của họa sĩ-II

// Thử nó!

// Cách tiếp cận ngây thơ cho vấn đề của họa sĩ:

// Một giải pháp mạnh mẽ là xem xét tất cả các tập hợp phân vùng liền kề có thể có và tính toán phân vùng tổng tối đa trong mỗi trường hợp và trả về mức tối thiểu của tất cả các trường hợp này.

// Phương pháp lập trình động cho bài toán Painter

// Cách tiếp cận trên có thể được tối ưu hóa hơn nữa bằng cách sử dụng phương pháp Lập trình động.

// Từ các ví dụ trên, rõ ràng là chiến lược chia bảng thành k phần bằng nhau sẽ không hiệu quả trong mọi trường hợp. Chúng ta có thể quan sát rằng bài toán có thể được chia thành: Cho một mảng A gồm các số nguyên không âm và một số nguyên dương k, chúng ta phải chia A thành k gồm ít phân vùng sao cho tổng lớn nhất của các phần tử trong một phân vùng, xét tổng thể. phân vùng được giảm thiểu. Vì vậy, đối với ví dụ thứ hai ở trên, các phép chia có thể là:

// Một phân vùng: vậy thời gian là 100.

// Hai phân vùng: (10) & (20, 30, 40) nên thời gian là 90. Tương tự, ta đặt phân số thứ nhất

// sau 20 (=> lần 70) hoặc 30 (=> lần 60); vì vậy điều này có nghĩa là thời gian tối thiểu: (100, 90, 70, 60) là 60.

// Cách tiếp cận cấu trúc con tối ưu cho bài toán của họa sĩ bằng cách sử dụng DP

// Chúng ta có thể triển khai giải pháp đơn giản bằng cách sử dụng đệ quy với thuộc tính cấu trúc con tối ưu sau:

// Giả sử rằng chúng ta đã có sẵn các phân vùng k-1 (sử dụng bộ chia k-2), bây giờ chúng ta phải đặt bộ chia thứ k-1 để có k phân vùng.

// Chúng ta có thể đặt dấu chia thứ k-1 giữa phần tử thứ i và i+1 trong đó i = 1 đến n.

// Xin lưu ý rằng việc đặt nó trước phần tử đầu tiên cũng giống như đặt nó sau phần tử cuối cùng.

// Tổng chi phí của sự sắp xếp này có thể được tính bằng giá trị tối đa sau đây:

// Giá của phân vùng cuối cùng: sum(Ai…..An), trong đó số chia thứ k-1 nằm trước phần tử i.

// Bạn có thể tìm ra điều này bằng cách sử dụng hàm trợ giúp đơn giản để tính tổng các phần tử giữa hai chỉ mục trong mảng.

// Chi phí tối đa của bất kỳ phân vùng nào đã được hình thành ở bên trái của dải phân cách thứ k-1.

// Chúng ta có thể nhận thấy rằng điều này thực ra là để đặt các dấu phân cách k-2 một cách công bằng nhất có thể, vì vậy đây là một bài toán con của bài toán đã cho.

// Do đó, chúng ta có thể viết thuộc tính cấu trúc con tối ưu dưới dạng mối quan hệ lặp lại sau:

// CPP program for The painter's partition problem
#include <climits>
#include <iostream>
using namespace std;

// function to calculate sum between two indices
// in array
int sum(int arr[], int from, int to)
{
    int total = 0;
    for (int i = from; i <= to; i++)
        total += arr[i];
    return total;
}

// for n boards and k partitions
int partition(int arr[], int n, int k)
{
    // base cases
    if (k == 1) // one partition
        return sum(arr, 0, n - 1);
    if (n == 1) // one board
        return arr[0];

    int best = INT_MAX;

    // find minimum of all possible maximum
    // k-1 partitions to the left of arr[i],
    // with i elements, put k-1 th divider
    // between arr[i-1] & arr[i] to get k-th
    // partition
    for (int i = 1; i <= n; i++)
        best = min(best, max(partition(arr, i, k - 1),
                             sum(arr, i, n - 1)));

    return best;
}

int main()
{
    int arr[] = {10, 20, 60, 50, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << partition(arr, n, k) << endl;

    return 0;
}

// A DP based CPP program for painter's partition problem
#include <climits>
#include <iostream>
using namespace std;

// function to calculate sum between two indices
// in array
int sum(int arr[], int from, int to)
{
    int total = 0;
    for (int i = from; i <= to; i++)
        total += arr[i];
    return total;
}

// bottom up tabular dp
int findMax(int arr[], int n, int k)
{
    // initialize table
    int dp[k + 1][n + 1] = {0};

    // base cases
    // k=1
    for (int i = 1; i <= n; i++)
        dp[1][i] = sum(arr, 0, i - 1);

    // n=1
    for (int i = 1; i <= k; i++)
        dp[i][1] = arr[0];

    // 2 to k partitions
    for (int i = 2; i <= k; i++)
    { // 2 to n boards
        for (int j = 2; j <= n; j++)
        {

            // track minimum
            int best = INT_MAX;

            // i-1 th separator before position arr[p=1..j]
            for (int p = 1; p <= j; p++)
                best = min(best, max(dp[i - 1][p],
                                     sum(arr, p, j - 1)));

            dp[i][j] = best;
        }
    }

    // required
    return dp[k][n];
}

// driver function
int main()
{
    int arr[] = {10, 20, 60, 50, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << findMax(arr, n, k) << endl;
    return 0;
}

// tối ưu
// Tối ưu hóa phương pháp lập trình động cho bài toán của Painter bằng cách sử dụng tính toán trước

// Độ phức tạp về thời gian của chương trình trên là O(k∗N3). Có thể dễ dàng giảm nó xuống O(k∗N2) bằng cách tính toán trước các tổng tích lũy trong một mảng, nhờ đó tránh được các lệnh gọi hàm tổng lặp lại.

// Dưới đây là cách chúng tôi có thể đạt được sự tối ưu hóa này:
// Optimising Dynamic Programming Approach for Painter’s Problem using Precomputation
// The time complexity of the above program is O(k∗N3). It can be easily brought down to O(k∗N2) by pre-computing the cumulative sums in an array, thus avoiding repeated calls to the sum function.

// Below is the how we can achieve this optimisation:

// int sum[n + 1] = { 0 };

// // sum from 1 to i elements of arr
// for (int i = 1; i <= n; i++)
//     sum[i] = sum[i - 1] + arr[i - 1];

// for (int i = 1; i <= n; i++)
//     dp[1][i] = sum[i];

// // and using it to calculate the result as:
// best = min(best, max(dp[i - 1][p], sum[j] - sum[p]));
// Note: Though here we consider dividing A into k or fewer partitions, we can observe that the optimal case always occurs when we divide A into exactly k partitions.

// So we can use:

// for (int i = k - 1; i <= n; i++)
//     best = min(best, max(partition(arr, i, k - 1),
//                          sum(arr, i, n - 1)));