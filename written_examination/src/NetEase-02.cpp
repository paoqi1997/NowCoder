#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x[n];
    vector<int> box;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        box.push_back(x[i]);
    }

    sort(box.begin(), box.end());

    int dist = box[1] - box[0];
    for (int i = 2; i < n; ++i) {
        if (box[i] - box[i - 1] != dist) {
            cout << "Impossible" << endl;
            return 0;
        }
    } cout << "Possible" << endl;

    return 0;
}
