#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/* 最大公约数 */
long gcd(long a, long b) {
    long t = a % b;
    while (t) {
        a = b; b = t; t = a % b;
    }
    return b;
}

long dp[25 + 1][6 * 25 + 1];

int main()
{
    int n, x;
    cin >> n >> x;

    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= 6; ++j) {
        dp[1][j] = 1;
    }

    // 前i个骰子在掷出j的情况下一共有多少种结果
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= 6 * i; ++j) {
            for (int k = 1; k <= 6; ++k) {
                // 第i个骰子掷出k
                if (j >= k) {
                    // 前i - 1个骰子掷出j - k
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
    }

    long x_sum = 0;
    for (int j = x; j <= 6 * n; ++j) {
        x_sum += dp[n][j];
    }

    long all_sum = pow(6, n);
    if (x_sum == 0) {
        cout << 0 << endl;
    } else if (x_sum == all_sum) {
        cout << 1 << endl;
    } else {
        long gcd_ = gcd(x_sum, all_sum);
        x_sum /= gcd_;
        all_sum /= gcd_;
        cout << x_sum << '/' << all_sum << endl;
    }

    return 0;
}
