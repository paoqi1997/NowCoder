#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;

    int m[n + 1], w[n + 1], s[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> m[i] >> w[i] >> s[i];
    }

    int dp[v + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= w[i]; --j) {
            for (int k = 1; k <= m[i] && k * w[i] <= j; ++k) {
                dp[j] = max(dp[j], dp[j - k * w[i]] + k * s[i]);
            }
        }
    } cout << dp[v] << endl;

    return 0;
}
