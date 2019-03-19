#include <iostream>
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

    int page, size;
    cin >> page >> size;

    int begin = page * size;
    int end = min((page + 1) * size, n);

    if (begin >= n) {
        cout << "超过分页范围" << endl;
    } else {
        for (int i = begin; i < end; ++i) {
            cout << x[i] << endl;
        }
    }

    return 0;
}
