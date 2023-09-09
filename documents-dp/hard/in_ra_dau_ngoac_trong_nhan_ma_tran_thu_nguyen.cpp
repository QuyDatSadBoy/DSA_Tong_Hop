// Cho một dãy ma trận, hãy tìm cách hiệu quả nhất để nhân các ma trận này với nhau. Vấn đề thực sự không phải là thực hiện các phép nhân mà chỉ là quyết định thứ tự thực hiện các phép nhân.

// Chúng ta có nhiều lựa chọn để nhân một chuỗi ma trận vì phép nhân ma trận có tính chất kết hợp. Nói cách khác, cho dù chúng ta đặt tích trong ngoặc như thế nào thì kết quả vẫn như nhau. Ví dụ: nếu chúng ta có bốn ma trận A, B, C và D, chúng ta sẽ có:

// (ABC)D = (AB)(CD) = A(BCD) = ....

// Tuy nhiên, thứ tự chúng ta đặt dấu ngoặc đơn vào tích sẽ ảnh hưởng đến số phép tính số học đơn giản cần thiết để tính tích hoặc hiệu quả. Ví dụ: giả sử A là ma trận 10 × 30, B là ma trận 30 × 5 và C là ma trận 5 × 60. Sau đó,

// (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 phép tính

// A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 phép tính.

// Rõ ràng dấu ngoặc đơn đầu tiên yêu cầu số lượng thao tác ít hơn.

// Cho một mảng p[] biểu thị chuỗi ma trận sao cho ma trận thứ i Ai có kích thước p[i-1] x p[i]. Chúng ta cần viết hàm MatrixChainOrder() để trả về số phép nhân tối thiểu cần thiết để nhân chuỗi.

// Đầu vào: p[] = {40, 20, 30, 10, 30}

// Đầu ra: Dấu ngoặc đơn tối ưu là ((A(BC))D)

// Chi phí đóng ngoặc tối ưu là 26000

// Có 4 ma trận có kích thước 40x20, 20x30,

// 30x10 và 10x30. Cho 4 ma trận đầu vào là A, B,

// C và D. Số phép nhân tối thiểu là

// thu được bằng cách đặt dấu ngoặc đơn theo cách sau

// (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

// Đầu vào: p[] = {10, 20, 30, 40, 30}

// Đầu ra: Dấu ngoặc đơn tối ưu là (((AB)C)D)

// Chi phí đóng ngoặc tối ưu là 30000

// Có 4 ma trận có kích thước 10x20, 20x30,

// 30x40 và 40x30. Cho 4 ma trận đầu vào là A, B,

// C và D. Số phép nhân tối thiểu là

// thu được bằng cách đặt dấu ngoặc đơn theo cách sau

// ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

// Đầu vào: p[] = {10, 20, 30}

// Đầu ra: Dấu ngoặc đơn tối ưu là (AB)

// Chi phí đóng ngoặc tối ưu là 6000

// Chỉ có hai ma trận có kích thước 10x20

// và 20x30. Vì vậy chỉ có một cách để nhân lên

// các ma trận có giá trị là 10*20*30

// Vấn đề này chủ yếu là một phần mở rộng của bài viết trước. Trong bài trước, chúng ta đã thảo luận về thuật toán chỉ tìm chi phí tối ưu. Ở đây chúng ta cũng cần in dấu ngoặc đơn.

// Ý tưởng là lưu trữ điểm dừng tối ưu cho mọi biểu thức con (i, j) trong khung mảng 2D[n][n]. Sau khi đã tạo mảng ngoặc, chúng ta có thể in dấu ngoặc đơn bằng mã bên dưới.

// // In dấu ngoặc đơn trong biểu thức con (i, j)

// printParenses(i, j, ngoặc [n] [n], tên)

// {

// // Nếu chỉ còn lại một ma trận trong đoạn hiện tại

// nếu (i == j)

// {

// in tên;

// tên++;

// trở lại;

// }

// in "(";

// // Đặt đệ quy các dấu ngoặc xung quanh biểu thức con

// // từ i đến ngoặc vuông[i][j].

// printParenesis(i, ngoặc [i] [j], ngoặc, tên);

// // Đặt đệ quy các dấu ngoặc xung quanh biểu thức con

// // từ ngoặc[i][j] + 1 đến j.

// printParenesis(ngoặc[i][j]+1, j, ngoặc, tên);

// in ")";

// }

// Dưới đây là cách thực hiện các bước trên.

// C++ program to print optimal parenthesization
// in matrix chain multiplication.
#include <bits/stdc++.h>
using namespace std;

// Function for printing the optimal
// parenthesization of a matrix chain product
void printParenthesis(int i, int j, int n, int *bracket,
                      char &name)
{
    // If only one matrix left in current segment
    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    // Note that "*((bracket+i*n)+j)" is similar to
    // bracket[i][j]
    printParenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name);
    cout << ")";
}

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
// Please refer below article for details of this
// function
// https://goo.gl/k6EYKj
void matrixChainOrder(int p[], int n)
{
    /* For simplicity of the program, one extra
    row and one extra column are allocated in
        m[][]. 0th row and 0th column of m[][]
        are not used */
    int m[n][n];

    // bracket[i][j] stores optimal break point in
    // subexpression from i to j.
    int bracket[n][n];

    /* m[i,j] = Minimum number of scalar multiplications
    needed to compute the matrix A[i]A[i+1]...A[j] =
    A[i..j] where dimension of A[i] is p[i-1] x p[i] */

    // cost is zero when multiplying one matrix.
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;

                    // Each entry bracket[i,j]=k shows
                    // where to split the product arr
                    // i,i+1....j for the minimum cost.
                    bracket[i][j] = k;
                }
            }
        }
    }

    // The first matrix is printed as 'A', next as 'B',
    // and so on
    char name = 'A';

    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n - 1, n, (int *)bracket, name);
    cout << "\nOptimal Cost is : " << m[1][n - 1];
}

// Driver code
int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    matrixChainOrder(arr, n);
    return 0;
}

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

// FinalCost class stores the final label and cost of the
// optimal solution
class FinalCost
{
public:
    string label = "";
    int cost = INT_MAX;
};

class MatrixMultiplyCost
{
public:
    // Recursive function that finds the optimal cost and
    // label

    void optimalCost(int **matrices, string *labels,
                     int prevCost, FinalCost &finalCost,
                     int len)
    {
        // Base case: If there are no or only one matrix,
        // the cost is 0 and there is no need for a label
        if (len < 2)
        {
            finalCost.cost = 0;
            return;
        }

        // Base case: If there are only two matrices, the
        // cost is the product of their dimensions and the
        // label is the concatenation of their labels
        else if (len == 2)
        {
            int cost = prevCost + (matrices[0][0] * matrices[0][1] * matrices[1][1]);
            if (cost < finalCost.cost)
            {
                finalCost.cost = cost;
                finalCost.label = "(" + labels[0] + labels[1] + ")";
            }
            return;
        }

        // Iterate through all possible matrix combinations
        for (int i = 0; i < len - 1; i++)
        {
            int j;

            // Create new matrices and labels after merging
            // two matrices
            int **newMatrix = new int *[len - 1];
            string *newLabels = new string[len - 1];
            int subIndex = 0;

            // Calculate the cost of merging matrices[i] and
            // matrices[i+1]
            int cost = (matrices[i][0] * matrices[i][1] * matrices[i + 1][1]);

            // Copy over the matrices and labels before the
            // merge
            for (j = 0; j < i; j++)
            {
                newMatrix[subIndex] = matrices[j];
                newLabels[subIndex++] = labels[j];
            }

            // Add the merged matrix and label
            newMatrix[subIndex] = new int[2];
            newMatrix[subIndex][0] = matrices[i][0];
            newMatrix[subIndex][1] = matrices[i + 1][1];
            newLabels[subIndex++] = "(" + labels[i] + labels[i + 1] + ")";

            // Copy over the matrices and labels after the
            // merge
            for (j = i + 2; j < len; j++)
            {
                newMatrix[subIndex] = matrices[j];
                newLabels[subIndex++] = labels[j];
            }

            // Recursively call the function with the new
            // matrices and labels
            optimalCost(newMatrix, newLabels,
                        prevCost + cost, finalCost,
                        len - 1);
        }
    }

    FinalCost findOptionalCost(int *arr, int len)
    {

        // Create matrices and labels from the input array
        int **matrices = new int *[len - 1];
        string *labels = new string[len - 1];
        for (int i = 0; i < len - 1; i++)
        {
            matrices[i] = new int[2];
            matrices[i][0] = arr[i];
            matrices[i][1] = arr[i + 1];
            labels[i] = char(
                65 + i); // Assign labels as A, B, C, etc.
        }
        FinalCost finalCost;

        // Call the recursive function to find the optimal
        // cost and label
        optimalCost(matrices, labels, 0, finalCost,
                    len - 1);
        return finalCost;
    }
};
void printMatrix(int **matrices, int len)
{
    cout << "matrices = " << endl
         << "[";
    for (int i = 0; i < len; i++)
    {
        cout << "[" << matrices[i][0] << " " << matrices[i][1] << "]"
             << " ";
    }
    cout << "]" << endl;
}

int main()
{
    MatrixMultiplyCost calc;

    int arr[] = {40, 20, 30, 10, 30};
    int len = sizeof(arr) / sizeof(arr[0]);
    int **matrices = new int *[len - 1];
    string *labels = new string[len - 1];

    for (int i = 0; i < len - 1; i++)
    {
        matrices[i] = new int[2];
        matrices[i][0] = arr[i];
        matrices[i][1] = arr[i + 1];
        labels[i] = char(65 + i);
    }

    printMatrix(matrices, len - 1);

    FinalCost cost = calc.findOptionalCost(arr, len);
    cout << "Final labels: \n"
         << cost.label << endl;
    cout << "Final Cost:\n"
         << cost.cost << endl;

    return 0;
}

// This code is contributed by lokeshpotta20.
