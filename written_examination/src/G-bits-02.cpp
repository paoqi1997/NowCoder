#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(x, x + n);

    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        cnt = max(cnt, abs(x[i] - x[i + 1]));
    }
    cout << cnt << endl;

    return 0;
}
