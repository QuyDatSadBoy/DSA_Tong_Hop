#include <iostream>
#include <vector>

using namespace std;

const int maxn = 16;    // Số lượng phần tử tối đa
const int maxsum = 150; // Tổng phần tử tối đa * 10^6

long long dp[maxn][maxsum];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        int sum = 0;

        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
            sum += A[i];
        }

        if (sum % 3 != 0)
        {
            cout << "0" << endl;
            continue;
        }

        sum /= 3;

        // Khởi tạo bước cơ sở
        for (int i = 0; i <= N; ++i)
            dp[i][0] = 1;

          for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= sum; ++j)
             {
                dp[i][j] = dp[i - 1][j];
                if (j >= A[i - 1])
                    dp[i][j] += dp[i - 1][j - A[i - 1]];
            }
        }

        cout << dp[N][sum] << endl;
    }

    return 0;
}