#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x;
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        q.push_back(x);
    }

    int day = 1, value = 0;
    while (q.size() > 1) {
        int l = q.front() * day, r = q.back() * day;
        if (l < r) {
            value += l; q.pop_front();
        } else {
            value += r; q.pop_back();
        }
        ++day;
    }

    cout << value + q.front() * day << endl;

    return 0;
}
