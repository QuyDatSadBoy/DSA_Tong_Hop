// Lập trình động (DP) là một kỹ thuật để giải quyết các vấn đề bằng cách chia chúng thành các vấn đề con chồng chéo theo cấu trúc con tối ưu. Có nhiều vấn đề khác nhau khi sử dụng DP như tổng tập hợp con, ba lô, đổi tiền, v.v. DP cũng có thể được áp dụng trên cây để giải quyết một số vấn đề cụ thể.

// Điều kiện tiên quyết: DFS

// Cho một cây có N nút và N-1 cạnh, hãy tính tổng tối đa các giá trị nút từ gốc đến bất kỳ lá nào mà không cần truy cập lại bất kỳ nút nào.

// Ở trên là sơ đồ của một cây có N=14 nút và N-1=13 cạnh. Các giá trị tại nút lần lượt là 3, 2, 1, 10, 1, 3, 9, 1, 5, 3, 4, 5, 9 và 8 cho các nút 1, 2, 3, 4….14.

// Sơ đồ bên dưới hiển thị tất cả các đường dẫn từ gốc đến lá:

// Tất cả các đường dẫn được đánh dấu bằng màu sắc khác nhau:

// Đường dẫn 1(đỏ, 3-2-1-4): tổng của tất cả các giá trị nút = 10

// Đường dẫn 2(cam, 3-2-1-5): tổng của tất cả các giá trị nút = 11

// Đường dẫn 3(màu vàng, 3-2-3): tổng của tất cả các giá trị nút = 8

// Đường dẫn 4(xanh, 3-1-9-9): tổng của tất cả các giá trị nút = 22

// Đường dẫn 5(violet, 3-1-9-8): tổng của tất cả các giá trị nút = 21

// Đường dẫn 6(hồng, 3-10-1): tổng của tất cả các giá trị nút = 14

// Đường dẫn 7(blue, 3-10-5): tổng của tất cả các giá trị nút = 18

// Đường dẫn 8(nâu, 3-10-3): tổng của tất cả các giá trị nút = 16

// Câu trả lời là 22, vì Đường 4 có tổng giá trị tối đa của các nút trên đường đi từ gốc đến lá.

// Cách tiếp cận tham lam không thành công trong trường hợp này. Bắt đầu từ gốc và lấy 3 từ cấp độ đầu tiên, 10 từ cấp độ tiếp theo và 5 từ cấp độ thứ ba một cách tham lam. Kết quả là path-7 nếu sau khi thực hiện theo cách tiếp cận tham lam, do đó không áp dụng cách tiếp cận tham lam ở đây.

// Vấn đề có thể được giải quyết bằng cách sử dụng Lập trình động trên cây. Bắt đầu ghi nhớ từ các lá và thêm số lá tối đa vào gốc của mỗi cây con. Ở bước cuối cùng, sẽ có gốc và cây con bên dưới nó, cộng giá trị tại nút và giá trị lớn nhất của cây con sẽ cho chúng ta tổng giá trị nút tối đa từ gốc đến bất kỳ lá nào.

// Sơ đồ trên cho thấy cách bắt đầu từ các lá và thêm số lá tối đa của cây con vào gốc của nó. Di chuyển lên trên và lặp lại quy trình tương tự để lưu trữ tối đa mỗi lá của cây con và thêm nó vào gốc của nó. Trong ví dụ này, tối đa nút 11 và 12 được lấy để đếm rồi cộng vào nút 5 (Trong cây con này, 5 là gốc và 11, 12 là lá của nó). Tương tự, lấy tối đa nút 13 và 14 rồi cộng vào nút 7. Lặp lại các bước cho từng cây con cho đến khi đạt đến nút.

// Gọi DPi là tổng lớn nhất của các giá trị nút trên đường đi giữa i và bất kỳ lá nào của nó di chuyển xuống dưới. Duyệt cây bằng cách duyệt DFS. Lưu trữ tối đa tất cả các lá của cây con và thêm nó vào gốc của cây con. Cuối cùng, DP1 sẽ có tổng giá trị nút tối đa từ gốc đến bất kỳ lá nào mà không cần truy cập lại bất kỳ nút nào.

// Dưới đây là cách thực hiện ý tưởng trên:

// C++ code to find the maximum path sum
#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

// function for dfs traversal and to store the
// maximum value in dp[] for every node till the leaves
void dfs(int a[], vector<int> v[], int u, int parent)
{
    // initially dp[u] is always a[u]
    dp[u] = a[u - 1];

    // stores the maximum value from nodes
    int maximum = 0;

    // traverse the tree
    for (int child : v[u])
    {

        // if child is parent, then we continue
        // without recursing further
        if (child == parent)
            continue;

        // call dfs for further traversal
        dfs(a, v, child, u);

        // store the maximum of previous visited node
        // and present visited node
        maximum = max(maximum, dp[child]);
    }

    // add the maximum value returned to the parent node
    dp[u] += maximum;
}

// function that returns the maximum value
int maximumValue(int a[], vector<int> v[])
{
    dfs(a, v, 1, 0);
    return dp[1];
}

// Driver Code
int main()
{
    // number of nodes
    int n = 14;

    // adjacency list
    vector<int> v[n + 1];

    // create undirected edges
    // initialize the tree given in the diagram
    v[1].push_back(2), v[2].push_back(1);
    v[1].push_back(3), v[3].push_back(1);
    v[1].push_back(4), v[4].push_back(1);
    v[2].push_back(5), v[5].push_back(2);
    v[2].push_back(6), v[6].push_back(2);
    v[3].push_back(7), v[7].push_back(3);
    v[4].push_back(8), v[8].push_back(4);
    v[4].push_back(9), v[9].push_back(4);
    v[4].push_back(10), v[10].push_back(4);
    v[5].push_back(11), v[11].push_back(5);
    v[5].push_back(12), v[12].push_back(5);
    v[7].push_back(13), v[13].push_back(7);
    v[7].push_back(14), v[14].push_back(7);

    // values of node 1, 2, 3....14
    int a[] = {3, 2, 1, 10, 1, 3, 9, 1, 5, 3, 4, 5, 9, 8};
    // initialise dp
    dp = vector<int>(n + 1, 0);
    // function call
    cout << maximumValue(a, v);

    return 0;
}
