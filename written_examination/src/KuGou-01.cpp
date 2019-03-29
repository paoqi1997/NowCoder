#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int y = n / 8; y >= 0; --y) {
        int x = (n - 8 * y) / 6;
        if (6 * x + 8 * y == n) {
            cout << x + y << endl;
            return 0;
        }
    } cout << -1 << endl;

    return 0;
}
