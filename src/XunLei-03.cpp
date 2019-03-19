#include <iostream>
#include <cstring>

using namespace std;

int n, m;

void dp() {
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j - i >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    } cout << dp[n][m] << endl;
}

void bag() {
    int dp[m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= i; --j) {
            dp[j] += dp[j - i];
        }
    } cout << dp[m] << endl;
}

int main()
{
    cin >> n >> m;

    if (true) {
        dp();
    } else {
        bag();
    }

    return 0;
}
