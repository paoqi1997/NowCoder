#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    if (s.size() == 1) {
        cout << 1 << endl;
    } else if (s.size() == 2) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
