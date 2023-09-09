// Cho thứ nguyên của dãy ma trận trong mảng arr[], trong đó thứ nguyên của ma trận thứ i là (arr[i-1] * arr[i]), nhiệm vụ là tìm ra cách hiệu quả nhất để nhân các ma trận này với nhau sao cho tổng số phép nhân phần tử là nhỏ nhất.

// Ví dụ:

// Đầu vào: mảng[] = {40, 20, 30, 10, 30}

// Đầu ra: 26000

// Giải thích: Có 4 ma trận có kích thước 40×20, 20×30, 30×10, 10×30.

// Cho 4 ma trận đầu vào là A, B, C và D.

// Số lượng  phép nhân tối thiểu thu được bằng cách

// đặt dấu ngoặc đơn như sau (A(BC))D.

// Tối thiểu là 20*30*10 + 40*20*10 + 40*10*30

// Đầu vào: mảng[] = {1, 2, 3, 4, 3}

// Đầu ra: 30

// Giải thích: Có 4 ma trận có kích thước 1×2, 2×3, 3×4, 4×3.

// Cho 4 ma trận đầu vào là A, B, C và D.

// Số lượng phép nhân tối thiểu thu được bằng cách

// đặt dấu ngoặc đơn theo cách sau ((AB)C)D.

// Số tối thiểu là 1*2*3 + 1*3*4 + 1*4*3 = 30

// Đầu vào: mảng[] = {10, 20, 30}

// Đầu ra: 6000

// Giải thích: Chỉ có hai ma trận có kích thước 10×20 và 20×30.

// Vì vậy, chỉ có một cách để nhân các ma trận, giá trị của ma trận là 10*20*30

// Phép nhân chuỗi ma trận bằng đệ quy:

// Chúng ta có thể giải quyết vấn đề bằng cách sử dụng đệ quy dựa trên các sự kiện và quan sát sau:

// Hai ma trận có kích thước m*n và n*p khi nhân với nhau sẽ tạo ra ma trận có kích thước m*p và số phép nhân thực hiện là m*n*p.

// Bây giờ, đối với một chuỗi N ma trận cho trước, việc phân vùng đầu tiên có thể được thực hiện theo N-1 cách. Ví dụ: dãy ma trận A, B, C và D có thể được nhóm thành (A)(BCD), (AB)(CD) hoặc (ABC)(D) theo 3 cách sau.

// Vì vậy, một phạm vi [i, j] có thể được chia thành hai nhóm như {[i, i+1], [i+1, j]}, {[i, i+2], [i+2, j]} , . . . , {[i, j-1], [j-1, j]}.

// Mỗi nhóm có thể được chia thành các nhóm nhỏ hơn và chúng ta có thể tìm thấy tổng số phép nhân cần thiết bằng cách giải từng nhóm.

// Số phép nhân tối thiểu trong số tất cả các phân vùng đầu tiên là câu trả lời bắt buộc.

// Thực hiện theo các bước được đề cập dưới đây để thực hiện phương pháp này:

// Tạo hàm đệ quy lấy i và j làm tham số xác định phạm vi của một nhóm.

// Lặp lại từ k = i đến j để phân vùng phạm vi đã cho thành hai nhóm.

// Gọi hàm đệ quy cho các nhóm này.

// Trả về giá trị tối thiểu trong số tất cả các phân vùng dưới dạng số phép nhân tối thiểu cần thiết để nhân tất cả các ma trận của nhóm này.

// Giá trị tối thiểu được trả về cho phạm vi từ 0 đến N-1 là câu trả lời bắt buộc.

// Dưới đây là cách thực hiện phương pháp trên.

// C++ code to implement the
// matrix chain multiplication using recursion

#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1 . . . n
int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int mini = INT_MAX;
    int count;

    // Place parenthesis at different places
    // between first and last matrix,
    // recursively calculate count of multiplications
    // for each parenthesis placement
    // and return the minimum count
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        mini = min(count, mini);
    }

    // Return minimum count
    return mini;
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, N - 1);
    return 0;
}

// This code is contributed by Shivi_Aggarwal

// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int *p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int *p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n);
}

// This code is contributed by Sumit_Yadav

// See the Cormen book for details of the
// following algorithm
#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(int p[], int n)
{

    /* For simplicity of the program, one
    extra row and one extra column are
    allocated in m[][]. 0th row and 0th
    column of m[][] are not used */
    int m[n][n];

    int i, j, k, L, q;

    /* m[i, j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */

    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, size);

    getchar();
    return 0;
}

// This code is contributed
// by Akanksha Rai
