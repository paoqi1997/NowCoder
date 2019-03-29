#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int m, n;
int x[1000][1000];
int result = INT_MIN;

void dfs(int x[][1000], int i, int j, int currVal, int trough) {
    if (result >= trough) {
        return;
    }
    if (i == m - 1 && j == n - 1) {
        result = trough;
    }
    if (i + 1 < m) {
        int nextVal = currVal + x[i + 1][j];
        if (nextVal < trough) {
            dfs(x, i + 1, j, nextVal, nextVal);
        } else {
            dfs(x, i + 1, j, nextVal, trough);
        }
    }
    if (j + 1 < n) {
        int nextVal = currVal + x[i][j + 1];
        if (nextVal < trough) {
            dfs(x, i, j + 1, nextVal, nextVal);
        } else {
            dfs(x, i, j + 1, nextVal, trough);
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x[i][j];
        }
    }

    dfs(x, 0, 0, x[0][0], x[0][0]);
    if (result >= 0) {
        cout << 1 << endl;
    } else {
        cout << abs(result) + 1 << endl;
    }

    return 0;
}
