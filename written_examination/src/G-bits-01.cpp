#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int cnt = 0;
    for (int i = m; i <= n; ++i) {
        bool flag = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++cnt;
        }
    } cout << cnt << endl;

    return 0;
}
