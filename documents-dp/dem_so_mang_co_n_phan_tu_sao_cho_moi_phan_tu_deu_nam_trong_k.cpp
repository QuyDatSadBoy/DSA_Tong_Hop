// Cho ba số nguyên dương n, k và x. Nhiệm vụ là đếm số mảng khác nhau có thể được tạo thành có kích thước n sao cho mỗi phần tử nằm trong khoảng từ 1 đến k và hai phần tử liên tiếp là khác nhau. Ngoài ra, phần tử đầu tiên và cuối cùng của mỗi mảng phải lần lượt là 1 và x.

// Ví dụ:

// Đầu vào: n = 4, k = 3, x = 2

// Đầu ra: 3

// Ý tưởng là sử dụng Lập trình động và tổ hợp để giải quyết vấn đề.

// Trước hết, lưu ý rằng câu trả lời giống nhau cho mọi x từ 2 đến k. Nó có thể dễ dàng được chứng minh. Điều này sẽ hữu ích sau này.

// Đặt trạng thái f(i) biểu thị số cách điền vào khoảng [1, i] của mảng A sao cho A1 = 1 và Ai ? 1.

// Vì vậy, nếu x? 1, đáp án của bài toán là f(n)/(k – 1), vì f(n) là số cách mà An được điền với một số từ 2 đến k và câu trả lời đều bằng nhau với tất cả các giá trị như vậy An, do đó đáp án cho một giá trị riêng lẻ là f(n)/(k – 1).

// Ngược lại, nếu x = 1 thì đáp án là f(n – 1), vì An – 1 ? 1, và số duy nhất chúng ta có thể điền vào An là x = 1.

// Bây giờ, vấn đề chính là làm thế nào để tính f(i). Xét tất cả các số mà Ai – 1 có thể có. Chúng ta biết rằng nó phải nằm trong [1, k].

// Nếu Ai – 1? 1 thì có (k – 2)f(i – 1) cách điền phần còn lại của mảng, vì Ai không thể là 1 hoặc Ai – 1 (nên ta nhân với (k – 2)), và với trong phạm vi [1, i – 1], có đệ quy f(i – 1) cách.

// Nếu Ai – 1 = 1 thì có (k – 1)f(i – 2) cách để điền vào phần còn lại của mảng, vì Ai – 1 = 1 có nghĩa là Ai – 2 ? 1 nghĩa là có f(i – 2) cách điền vào khoảng [1, i – 2] và giá trị duy nhất mà Ai không thể bằng 1, nên ta có (k – 1) lựa chọn cho Ai.

// Bằng cách kết hợp những điều trên, chúng ta có được

// f(i) = (k - 1) * f(i - 2) + (k - 2) * f(i - 1)

// Điều này sẽ giúp chúng ta sử dụng quy hoạch động sử dụng f(i).

// Dưới đây là cách thực hiện phương pháp này:

// CPP Program to find count of arrays.
#include <bits/stdc++.h>
#define MAXN 109
using namespace std;

// Return the number of arrays with given constraints.
int countarray(int n, int k, int x)
{
    int dp[MAXN] = {0};

    // Initialising dp[0] and dp[1].
    dp[0] = 0;
    dp[1] = 1;

    // Computing f(i) for each 2 <= i <= n.
    for (int i = 2; i < n; i++)
        dp[i] = (k - 2) * dp[i - 1] +
                (k - 1) * dp[i - 2];

    return (x == 1 ? (k - 1) * dp[n - 2] : dp[n - 1]);
}

// Driven Program
int main()
{
    int n = 4, k = 3, x = 2;
    cout << countarray(n, k, x) << endl;
    return 0;
}

// CPP Program to find count of arrays.
#include <bits/stdc++.h>
#define MAXN 109
using namespace std;

// Return the number of arrays with given constraints.
int countarray(int n, int k, int x)
{
    // initialize variables to store previous values
    int prev1 = 0, prev2 = 1, curr;

    // Computing f(i) for each 2 <= i <= n.
    for (int i = 2; i < n; i++)
    {
        curr = (k - 2) * prev2 + (k - 1) * prev1;

        // assigning values to iterate further
        prev1 = prev2;
        prev2 = curr;
    }

    // return final answer
    return (x == 1 ? (k - 1) * prev1 : prev2);
}

// Driven Program
int main()
{
    int n = 4, k = 3, x = 2;

    // function call
    cout << countarray(n, k, x) << endl;
    return 0;
}
