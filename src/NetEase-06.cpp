#include <iostream>

using namespace std;

int dp[10 + 1][100000 + 1];
const int mod = 1000000007;

int main()
{
    int n, k;
    cin >> n >> k;

    // 长度为1且尾数为j的数列个数
    for (int j = 1; j <= k; ++j) {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        int sum = 0;
        // 上一行的数列个数
        for (int j = 1; j <= k; ++j) {
            sum = (sum + dp[i - 1][j]) % mod;
        }
        for (int j = 1; j <= k; ++j) {
            // 排除掉A % B == 0的情况
            int invalid = 0;
            for (int b = 2; b * j <= k; ++b) {
                invalid = (invalid + dp[i - 1][b * j]) % mod;
            }
            // +mod是为了应对sum - invalid < 0的情况
            dp[i][j] = (sum - invalid + mod) % mod;
        }
    }

    int cnt = 0;
    for (int j = 1; j <= k; ++j) {
        cnt = (cnt + dp[n][j]) % mod;
    }
    cout << cnt << endl;

    return 0;
}
