#include <iostream>
#include <cstring>

using namespace std;

int dp(int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= m; ++i) {
        dp[i][1] = 1;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j > i) {
                dp[i][j] = dp[i][i];
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            }
        }
    } return dp[m][n];
}

int fn(int m, int n) {
    // m == 0 <-> 没有水可倒入
    // n == 1 <-> 所有的水都倒入一个容器里
    if (m == 0 || n == 1) {
        return 1;
    }
    if (n > m) {
        // 必定有n - m个容器空着
        return fn(m, m);
    } else {
        // fn(m, n - 1) <-> 至少有一个容器空着
        // fn(m - n, n) <-> 每个容器都倒入一升水
        return fn(m, n - 1) + fn(m - n, n);
    }
}

int main()
{
    int x;
    cin >> x;

    for (int i = 0; i < x; ++i) {
        int m, n;
        cin >> m >> n;
        if (true) {
            cout << dp(m, n) << endl;
        } else {
            cout << fn(m, n) << endl;
        }
    }

    return 0;
}
