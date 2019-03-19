#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x, max, max2;
    max = max2 = INT_MIN;
    while (cin >> x) {
        if (max < x) {
            // max2 < max < x
            max2 = max, max = x;
        } else if (max2 < x) {
            // max2 < x < max
            max2 = x;
        }
    } cout << max2 << endl;

    return 0;
}
