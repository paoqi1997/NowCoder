#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int x[t];
    vector<string> box;
    for (int i = 0; i < t; ++i) {
        cin >> x[i];
        box.push_back(to_string(x[i]));
    }

    for (int i = 0; i < t; ++i) {
        bool flag = false;
        do {
            string s = box[i];
            if (stoi(s) != x[i] && stoi(s) % x[i] == 0) {
                flag = true;
                break;
            }
        } while (next_permutation(box[i].begin(), box[i].end()));
        if (flag) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
