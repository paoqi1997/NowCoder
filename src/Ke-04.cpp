#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;

    if (k == 1) {
        cout << 1 << endl;
    } else if (k == 2) {
        cout << 1 << endl;
    } else {
        int x1 = 1, x2 = 1, x3;
        for (int i = 3; i <= k; ++i) {
            x3 = x1 + x2;
            x1 = x2, x2 = x3;
        }
        cout << x3 << endl;
    }

    return 0;
}
