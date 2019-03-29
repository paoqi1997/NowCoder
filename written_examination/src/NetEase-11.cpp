#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    int x[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(x, x + n);

    int dist = x[n - 1] - x[0];

    for (int i = 0; i < n - 1; ++i) {
        // 左端
        int l = min(x[0] + s, x[i + 1] - s);
        // 右端
        int r = max(x[i] + s, x[n - 1] - s);
        // 最小距离
        dist = min(dist, r - l);
    }

    cout << dist << endl;

    return 0;
}
