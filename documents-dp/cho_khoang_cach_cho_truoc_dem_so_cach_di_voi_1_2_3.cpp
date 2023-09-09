// Cho khoảng cách 'dist', đếm tổng số cách để đi hết khoảng cách đó bằng 1, 2 và 3 bước.

// Ví dụ:

// Đầu vào: n = 3

// Đầu ra: 4

// Giải trình:

// Dưới đây là bốn cách

// 1 bước + 1 bước + 1 bước

// 1 bước + 2 bước

// 2 bước + 1 bước

// 3 bước

// Đầu vào: n = 4

// Đầu ra: 7

// Giải trình:

// Dưới đây là bốn cách

// 1 bước + 1 bước + 1 bước + 1 bước

// 1 bước + 2 bước + 1 bước

// 2 bước + 1 bước + 1 bước

// 1 bước + 1 bước + 2 bước

// 2 bước + 2 bước

// 3 bước + 1 bước

// 1 bước + 3 bước

// A naive recursive C++ program to count number of ways to cover
// a distance with 1, 2 and 3 steps
#include <iostream>
using namespace std;

// Returns count of ways to cover 'dist'
int printCountRec(int dist)
{
    // Base cases
    if (dist < 0)
        return 0;
    if (dist == 0)
        return 1;

    // Recur for all previous 3 and add the results
    return printCountRec(dist - 1) +
           printCountRec(dist - 2) +
           printCountRec(dist - 3);
}

// driver program
int main()
{
    int dist = 4;
    cout << printCountRec(dist);
    return 0;
}

// A Dynamic Programming based C++ program to count number of ways
// to cover a distance with 1, 2 and 3 steps
#include <iostream>
using namespace std;

int printCountDP(int dist)
{
    int count[dist + 1];

    // Initialize base values. There is one way to cover 0 and 1
    // distances and two ways to cover 2 distance
    count[0] = 1;
    if (dist >= 1)
        count[1] = 1;
    if (dist >= 2)
        count[2] = 2;

    // Fill the count array in bottom up manner
    for (int i = 3; i <= dist; i++)
        count[i] = count[i - 1] + count[i - 2] + count[i - 3];

    return count[dist];
}

// driver program
int main()
{
    int dist = 4;
    cout << printCountDP(dist);
    return 0;
}

// A Dynamic Programming based C++ program to count number of ways
#include <iostream>
using namespace std;

int printCountDP(int dist)
{
    // Create the array of size 3.
    int ways[3], n = dist;

    // Initialize the bases cases
    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;

    // Run a loop from 3 to n
    // Bottom up approach to fill the array
    for (int i = 3; i <= n; i++)
        ways[i % 3] = ways[(i - 1) % 3] + ways[(i - 2) % 3] + ways[(i - 3) % 3];

    return ways[n % 3];
}

// driver program
int main()
{
    int dist = 4;
    cout << printCountDP(dist);
    return 0;
}
