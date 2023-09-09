// Cho một cây có N nút và N-1 cạnh, hãy tìm chiều cao tối đa của cây khi bất kỳ nút nào trong cây được coi là gốc của cây.

// Sơ đồ trên biểu thị một cây có 11 nút và 10 cạnh và đường dẫn cho chúng ta chiều cao tối đa khi nút 1 được coi là gốc. Chiều cao tối đa là 3.

// Trong sơ đồ trên, khi 2 được coi là gốc thì đường đi dài nhất được tìm thấy có màu ĐỎ. Một cách tiếp cận đơn giản là duyệt cây bằng cách sử dụng phép truyền tải DFS cho mọi nút và tính chiều cao tối đa khi nút được coi là gốc của cây. Độ phức tạp về thời gian để duyệt DFS của cây là O(N). Độ phức tạp về thời gian tổng thể của DFS cho tất cả N nút sẽ là O(N)*N tức là O(N2).

// Vấn đề trên có thể được giải quyết bằng cách sử dụng Lập trình động trên cây. Để giải quyết vấn đề này, hãy tính toán trước hai thứ cho mỗi nút. Một sẽ có chiều cao tối đa khi di chuyển từ cành xuống lá. Trong khi cái còn lại sẽ có chiều cao tối đa khi di chuyển lên trên qua lá mẹ của nó tới bất kỳ lá nào.

// Cấu trúc tối ưu:

// Khi nút i được coi là nút gốc,

// in[i] là chiều cao tối đa của cây khi chúng ta di chuyển xuống dưới qua các cây con và lá của nó.

// Ngoài ra, out[i] là chiều cao tối đa của cây khi di chuyển lên trên qua cây mẹ của nó.

// Chiều cao tối đa của cây khi nút i là

// được coi là gốc sẽ là max(in[i], out[i]).

// Tính toán trong [i]:

// Trong hình trên, các giá trị trong [i] đã được tính cho mọi nút i. Giá trị lớn nhất của mỗi cây con được lấy và cộng thêm 1 vào cây cha của cây con đó. Thêm 1 cho cạnh giữa cây cha và cây con. Duyệt cây bằng DFS và tính in[i] là max(in[i], 1+in[child]) cho mỗi nút.

// Tính toán out[i]:

// Sơ đồ trên hiển thị tất cả các giá trị out[i] và đường dẫn. Để tính toán out[i], hãy di chuyển lên trên nút cha của nút i. Từ nút cha của nút i, có hai cách để di chuyển vào, một cách là ở tất cả các nhánh của nút cha. Hướng còn lại là di chuyển đến nút cha (gọi là parent2 để tránh nhầm lẫn) của nút cha (gọi là parent1) của nút i. Chiều cao tối đa trở lên qua parent2 chính là out[parent1]. Nói chung, out[nút i] là 1+max(out[i], 1+max của tất cả các nhánh). Thêm 1 cho các cạnh giữa nút và nút cha.

// Sơ đồ trên giải thích cách tính out[i] khi 2 được coi là gốc của cây. Các nhánh của nút 2 không được tính vì chiều cao tối đa qua đường dẫn đó đã được tính toán và lưu trữ trong i[2]. Tiến lên, trong trường hợp này, cha của 2, tức là 1, không có cha. Vì vậy, các nhánh ngoại trừ nhánh có nút sẽ được xem xét khi tính giá trị tối đa.

// Sơ đồ trên giải thích cách tính out[10]. Nút cha của nút 10, tức là 7 có nút cha và một nhánh (chính xác là nút con trong trường hợp này). Vì vậy, chiều cao tối đa của cả hai đã được tính trong những trường hợp như vậy khi cha mẹ và nhánh tồn tại.

// Trong trường hợp có nhiều nhánh của nút gốc, hãy đếm nhánh dài nhất trong số chúng (không bao gồm nhánh mà nút nằm trong đó)

// Tính chiều cao tối đa của tất cả các nhánh được kết nối với cha mẹ:

// in[i] lưu chiều cao tối đa khi di chuyển xuống dưới. Không cần phải lưu trữ tất cả chiều dài của cành cây. Chỉ độ dài tối đa thứ nhất và thứ hai trong số tất cả các nhánh mới đưa ra câu trả lời. Vì thuật toán được sử dụng dựa trên DFS nên tất cả các nhánh được kết nối với nhánh chính sẽ được xem xét, bao gồm cả nhánh có nút. Nếu đường dẫn cực đại đầu tiên thu được giống như trong [i] thì max1 là độ dài của nhánh chứa nút i. Trong trường hợp này, đường đi dài nhất của chúng ta sẽ là max2.

// Mối quan hệ lặp lại của in[i] và out[i]:

// in[i] = max(in[i], 1 + in[child])

// out[i] = 1 + max(out[parent of i], 1 + đường đi dài nhất trong tất cả các nhánh của cha mẹ của i)

// Dưới đây là cách thực hiện ý tưởng trên:

// C++ code to find the maximum path length
// considering any node as root
#include <bits/stdc++.h>
using namespace std;

vector<int> in, out;

// function to pre-calculate the array in[]
// which stores the maximum height when travelled
// via branches
void dfs1(vector<int> v[], int u, int parent)
{
    // initially every node has 0 height
    in[u] = 0;

    // traverse in the subtree of u
    for (int child : v[u])
    {

        // if child is same as parent
        if (child == parent)
            continue;

        // dfs called
        dfs1(v, child, u);

        // recursively calculate the max height
        in[u] = max(in[u], 1 + in[child]);
    }
}

// function to pre-calculate the array out[]
// which stores the maximum height when traveled
// via parent
void dfs2(vector<int> v[], int u, int parent)
{
    // stores the longest and second
    // longest branches
    int mx1 = -1, mx2 = -1;

    // traverse in the subtrees of u
    for (int child : v[u])
    {
        if (child == parent)
            continue;

        // compare and store the longest
        // and second longest
        if (in[child] >= mx1)
        {
            mx2 = mx1;
            mx1 = in[child];
        }

        else if (in[child] > mx2)
            mx2 = in[child];
    }

    // traverse in the subtree of u
    for (int child : v[u])
    {
        if (child == parent)
            continue;

        int longest = mx1;

        // if longest branch has the node, then
        // consider the second longest branch
        if (mx1 == in[child])
            longest = mx2;

        // recursively calculate out[i]
        out[child] = 1 + max(out[u], 1 + longest);

        // dfs function call
        dfs2(v, child, u);
    }
}

// function to print all the maximum heights
// from every node
void printHeights(vector<int> v[], int n)
{
    // traversal to calculate in[] array
    dfs1(v, 1, 0);

    // traversal to calculate out[] array
    dfs2(v, 1, 0);

    // print all maximum heights
    for (int i = 1; i <= n; i++)
        cout << "The maximum height when node "
             << i << " is considered as root"
             << " is " << max(in[i], out[i])
             << "\n";
}

// Driver Code
int main()
{
    int n = 11;
    vector<int> v[n + 1];

    // initialize the tree given in the diagram
    v[1].push_back(2), v[2].push_back(1);
    v[1].push_back(3), v[3].push_back(1);
    v[1].push_back(4), v[4].push_back(1);
    v[2].push_back(5), v[5].push_back(2);
    v[2].push_back(6), v[6].push_back(2);
    v[3].push_back(7), v[7].push_back(3);
    v[7].push_back(10), v[10].push_back(7);
    v[7].push_back(11), v[11].push_back(7);
    v[4].push_back(8), v[8].push_back(4);
    v[4].push_back(9), v[9].push_back(4);

    // initialise in and out vectors
    in.resize(n + 1, 0);
    out.resize(n + 1, 0);
    // function to print the maximum height from every node
    printHeights(v, n);

    return 0;
}
