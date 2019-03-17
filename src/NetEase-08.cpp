#include <iostream>

using namespace std;

int main()
{
    int x[5];
    for (int i = 0; i < 5; ++i) {
        cin >> x[i];
    }

    int val = 0, count = 0;
    while (count < 3) {
        ++val;
        count = 0;
        for (auto c : x) {
            if (val % c == 0) {
                ++count;
            }
        }
    } cout << val << endl;

    return 0;
}
