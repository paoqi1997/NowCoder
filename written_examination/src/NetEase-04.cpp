#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x[n];
    deque<int> box;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        if (i % 2 == 0) {
            box.push_back(x[i]);
        } else {
            box.push_front(x[i]);
        }
    }

    if (n % 2 == 0) {
        for (auto it = box.begin(); it != box.end(); ++it) {
            cout << *it << ' ';
        }
    } else {
        for (auto it = box.rbegin(); it != box.rend(); ++it) {
            cout << *it << ' ';
        }
    } cout << endl;

    return 0;
}
