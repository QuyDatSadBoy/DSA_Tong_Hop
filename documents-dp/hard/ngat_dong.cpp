// Cho một chuỗi các từ và giới hạn số lượng ký tự có thể đặt trong một dòng (độ rộng dòng). Đặt các ngắt dòng theo trình tự nhất định sao cho các dòng được in gọn gàng. Giả sử rằng chiều dài của mỗi từ nhỏ hơn chiều rộng của dòng.

// Các bộ xử lý văn bản như MS Word thực hiện nhiệm vụ đặt dấu ngắt dòng. Ý tưởng là có đường cân bằng. Nói cách khác, không nên có vài dòng có nhiều khoảng trắng thừa và một số dòng có ít khoảng trắng thừa.

// Các khoảng trắng thừa bao gồm các khoảng trắng được đặt ở cuối mỗi dòng ngoại trừ dòng cuối cùng.

// Vấn đề là giảm thiểu tổng chi phí sau đây.

// Chi phí của một dòng = (Số khoảng trắng thừa trong dòng)^3

// Tổng chi phí = Tổng chi phí cho tất cả các dòng

// Ví dụ: hãy xem xét chuỗi và độ rộng dòng sau M = 15

// "Geeks for Geeks trình bày vấn đề về ngắt từ"

// Sau đây là cách sắp xếp tối ưu các từ trong 3 dòng

// Geek dành cho Geek

// quà từ

// vấn đề bọc

// Tổng số khoảng trống thừa ở dòng 1, dòng 2 và dòng 3 lần lượt là 0, 2 và 3.

// Vậy giá trị tối ưu của tổng chi phí là 0 + 2*2*2 + 3*3*3 = 35

// Xin lưu ý rằng hàm tổng chi phí không phải là tổng của các khoảng trống thừa mà là tổng các khối (hoặc hình vuông cũng được sử dụng) của các khoảng trống thừa. Ý tưởng đằng sau hàm chi phí này là cân bằng khoảng cách giữa các dòng. Ví dụ: hãy xem xét hai cách sắp xếp sau đây của cùng một bộ từ:

// 1) Có 3 dòng. Một dòng có thêm 3 khoảng trắng và tất cả các dòng khác có thêm 0 khoảng trắng. Tổng số khoảng trống thừa = 3 + 0 + 0 = 3. Tổng chi phí = 3*3*3 + 0*0*0 + 0*0*0 = 27.

// 2) Có 3 dòng. Mỗi dòng trong số 3 dòng có thêm một khoảng trống. Tổng số không gian thừa = 1 + 1 + 1 = 3. Tổng chi phí = 1*1*1 + 1*1*1 + 1*1*1 = 3.

// Tổng số khoảng trắng thừa là 3 trong cả hai trường hợp, nhưng nên ưu tiên sắp xếp thứ hai vì các khoảng trắng thừa được cân bằng ở cả ba dòng. Hàm chi phí với tổng khối phục vụ mục đích vì giá trị của tổng chi phí trong kịch bản thứ hai nhỏ hơn.

// Khuyến nghị: Vui lòng giải quyết nó trên phần “THỰC HÀNH” trước khi chuyển sang giải pháp.

// Cách 1 (Giải pháp tham lam)

// Giải pháp tham lam là đặt càng nhiều từ càng tốt ở dòng đầu tiên. Sau đó làm tương tự cho dòng thứ hai và cứ như vậy cho đến khi đặt hết tất cả các từ. Giải pháp này cho lời giải tối ưu trong nhiều trường hợp nhưng không cho lời giải tối ưu trong mọi trường hợp. Ví dụ: hãy xem xét chuỗi sau đây “aaa bb cc ddddd” và độ rộng dòng là 6. Phương thức Greedy sẽ tạo ra kết quả như sau.

// aaa bb

// cc

// ddddd

// Dấu cách thừa ở 3 dòng trên lần lượt là 0, 4 và 1. Vậy tổng chi phí là 0 + 64 + 1 = 65.

// Nhưng giải pháp trên không phải là giải pháp tốt nhất. Sự sắp xếp sau đây có không gian cân bằng hơn. Do đó giá trị của hàm tổng chi phí ít hơn.

// aaa

// bb cc

// ddddd

// Dấu cách thừa ở 3 dòng trên lần lượt là 3, 1 và 1. Vậy tổng chi phí là 27 + 1 + 1 = 29.

// Mặc dù chưa tối ưu trong một số trường hợp, cách tiếp cận tham lam vẫn được nhiều bộ xử lý văn bản như MS Word và OpenOffice.org Writer sử dụng.

// Phương pháp 2 (Phương pháp đệ quy có ghi nhớ)

// Vấn đề có thể được giải quyết bằng cách sử dụng phương pháp phân chia và chinh phục (đệ quy). Thuật toán tương tự được đề cập dưới đây:

// 1. Chúng tôi lặp lại cho mỗi từ bắt đầu bằng từ đầu tiên và độ dài còn lại của dòng (ban đầu là k).

// 2. Từ cuối cùng sẽ là trường hợp cơ bản:

// Chúng tôi kiểm tra xem chúng tôi có thể đặt nó trên cùng một dòng không:

// nếu có thì chúng tôi trả về chi phí là 0.

// nếu không, chúng tôi trả về chi phí của dòng hiện tại dựa trên độ dài còn lại của nó.

// 3. Đối với các từ không phải là cuối cùng, chúng ta phải kiểm tra xem nó có thể vừa với dòng hiện tại hay không:

// nếu có thì chúng ta có hai lựa chọn, tức là đặt nó ở cùng dòng hay dòng tiếp theo.

// nếu chúng ta đặt nó ở dòng tiếp theo: cost1 = Square(remLength) + cost của việc đặt Word ở dòng tiếp theo.

// nếu chúng ta đặt nó trên cùng một dòng: cost2 = chi phí đặt từ trên cùng một dòng.

// trả lại tối thiểu(chi phí1, chi phí2)

// nếu không thì chúng ta phải đặt nó ở dòng tiếp theo:

// trả lại chi phí đặt từ trên dòng tiếp theo

// 4. Chúng tôi sử dụng bảng ghi nhớ có kích thước n (số từ) * k (độ dài dòng), để theo dõi các vị trí đã truy cập.

#include <bits/stdc++.h>
using namespace std;

int solveWordWrapUsingMemo(int words[], int n, int length,
                           int wordIndex, int remLength,
                           vector<vector<int>> memo);

int square(int n) { return n * n; }

int solveWordWrapUtil(int words[], int n, int length,
                      int wordIndex, int remLength,
                      vector<vector<int>> memo)
{

    // base case for last word
    if (wordIndex == n - 1)
    {
        memo[wordIndex][remLength] = words[wordIndex] < remLength
                                         ? 0
                                         : square(remLength);
        return memo[wordIndex][remLength];
    }

    int currWord = words[wordIndex];
    // if word can fit in the remaining line
    if (currWord < remLength)
    {
        return min(solveWordWrapUsingMemo(
                       words, n, length, wordIndex + 1,
                       remLength == length
                           ? remLength - currWord
                           : remLength - currWord - 1,
                       memo),

                   square(remLength) + solveWordWrapUsingMemo(
                                           words, n, length, wordIndex + 1,
                                           length - currWord, memo));
    }
    else
    {
        // if word is kept on next line
        return square(remLength) + solveWordWrapUsingMemo(
                                       words, n, length, wordIndex + 1,
                                       length - currWord, memo);
    }
}

int solveWordWrapUsingMemo(int words[], int n, int length,
                           int wordIndex, int remLength,
                           vector<vector<int>> memo)
{
    if (memo[wordIndex][remLength] != -1)
    {
        return memo[wordIndex][remLength];
    }

    memo[wordIndex][remLength] = solveWordWrapUtil(
        words, n, length, wordIndex, remLength, memo);
    return memo[wordIndex][remLength];
}

int solveWordWrap(int words[], int n, int k)
{

    vector<vector<int>> memo(n, vector<int>(k + 1, -1));

    return solveWordWrapUsingMemo(words, n, k, 0, k, memo);
}
int main()
{
    int words[] = {3, 2, 2, 5};
    int n = sizeof(words) / sizeof(words[0]);
    int k = 6;

    cout << solveWordWrap(words, n, k);
    return 0;
}
/* This Code is contributed by Tapesh (tapeshdua420) */

// A Dynamic programming solution for Word Wrap Problem
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

// A utility function to print the solution
int printSolution(int p[], int n);

// l[] represents lengths of different words in input sequence.
// For example, l[] = {3, 2, 2, 5} is for a sentence like
// "aaa bb cc ddddd". n is size of l[] and M is line width
// (maximum no. of characters that can fit in a line)
void solveWordWrap(int l[], int n, int M)
{
    // For simplicity, 1 extra space is used in all below arrays

    // extras[i][j] will have number of extra spaces if words from i
    // to j are put in a single line
    int extras[n + 1][n + 1];

    // lc[i][j] will have cost of a line which has words from
    // i to j
    int lc[n + 1][n + 1];

    // c[i] will have total cost of optimal arrangement of words
    // from 1 to i
    int c[n + 1];

    // p[] is used to print the solution.
    int p[n + 1];

    int i, j;

    // calculate extra spaces in a single line. The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line
    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i - 1];
        for (j = i + 1; j <= n; j++)
            extras[i][j] = extras[i][j - 1] - l[j - 1] - 1;
    }

    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lc[i][j] indicates cost of putting words from
    // word number i to j in a single line
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && extras[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j] * extras[i][j];
        }
    }

    // Calculate minimum cost and find minimum cost arrangement.
    // The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i - 1] != INF && lc[i][j] != INF &&
                (c[i - 1] + lc[i][j] < c[j]))
            {
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }

    printSolution(p, n);
}

int printSolution(int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution(p, p[n] - 1) + 1;
    cout << "Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
    return k;
}

// Driver program to test above functions
int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l) / sizeof(l[0]);
    int M = 6;
    solveWordWrap(l, n, M);
    return 0;
}

// This is code is contributed by rathbhupendra

#include <iostream>
using namespace std;

void solveWordWrap(int n, int arr[], int k)
{
    // initialize total cost
    int total_cost = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // size of window left after the current element
        int size = k - 1 - arr[i];
        // cost of current line
        int sum = k - arr[i];
        while (size >= 0)
        {
            size = size - arr[i + 1] - 1;
            // breaks immediately
            if (size < 0)
            {
                break;
            }
            sum = sum - arr[i] - 1;
            i++;
        }
        // add current cost to total cost
        total_cost = total_cost + (sum * sum);
    }
    // print the total cost
    cout << total_cost;
}

int main()
{
    int n = 4;
    int nums[n] = {3, 2, 2, 5};
    int k = 6;
    solveWordWrap(n, nums, k);
}
// this code is contributed by Sanyam Jain
