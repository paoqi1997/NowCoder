#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int h[n];
    vector<int> box;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        box.push_back(h[i]);
    }

    sort(box.begin(), box.end());

    int min = box[0];
    int max = box[n - 1];
    int crazy = max - min;

    int next_min_index = 1;
    int next_max_index = n - 2;

    while (next_min_index < next_max_index) {
        crazy += max - box[next_min_index];
        crazy += box[next_max_index] - min;
        min = box[next_min_index++];
        max = box[next_max_index--];
    }

    crazy += std::max(max - box[next_min_index], box[next_max_index] - min);
    cout << crazy << endl;

    return 0;
}
