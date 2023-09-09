// Đầu vào: n = 2 k = 4

// Đầu ra: 16

// Giải thích: Chúng ta có 4 màu và 2 bài viết.

// Những cách khi cả hai bài viết có cùng màu :4

// Các cách khi cả hai bài đăng có màu khác nhau :4(lựa chọn cho bài đăng đầu tiên) * 3(lựa chọn cho bài đăng thứ 2) = 12

// Đầu vào: n = 3 k = 2

// Đầu ra: 6

// C++ program for Painting Fence Algorithm
// optimised version

#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts
long countWays(int n, int k)
{
	long dp[n + 1];
	memset(dp, 0, sizeof(dp));
	long long mod = 1000000007;

	dp[1] = k;
	dp[2] = k * k;

	for (int i = 3; i <= n; i++) {
		dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
	}

	return dp[n];
}

// Driver code
int main()
{
	int n = 3, k = 2;
	cout << countWays(n, k) << endl;
	return 0;
}


// C++ program for Painting Fence Algorithm
#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts
// using k colors
long countWays(int n, int k)
{
	// There are k ways to color first post
	long total = k;
	int mod = 1000000007;

	// There are 0 ways for single post to
	// violate (same color) and k ways to
	// not violate (different color)
	int same = 0, diff = k;

	// Fill for 2 posts onwards
	for (int i = 2; i <= n; i++) {
		// Current same is same as previous diff
		same = diff;

		// We always have k-1 choices for next post
		diff = total * (k - 1);
		diff = diff % mod;

		// Total choices till i.
		total = (same + diff) % mod;
	}

	return total;
}

// Driver code
int main()
{
	int n = 3, k = 2;
	cout << countWays(n, k) << endl;
	return 0;
}
