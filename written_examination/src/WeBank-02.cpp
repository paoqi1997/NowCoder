#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int x[n + 1][m + 1];
    memset(x, 0, sizeof(x));

    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; ++j) {
            int woman;
            cin >> woman;
            x[i][woman] = 1;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; ++j) {
            int man;
            cin >> man;
            x[man][i] = 1;
        }
    }

    int cnt = 0;
    // 男士需要的舞曲
    for (int i = 1; i <= n; ++i) {
        int _cnt = 0;
        for (int j = 1; j <= m; ++j) {
            _cnt += x[i][j];
        }
        cnt = max(cnt, _cnt);
    }
    // 女士需要的舞曲
    for (int i = 1; i <= m; ++i) {
        int _cnt = 0;
        for (int j = 1; j <= n; ++j) {
            _cnt += x[j][i];
        }
        cnt = max(cnt, _cnt);
    }
    cout << cnt << endl;

    return 0;
}
