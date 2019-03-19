#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
    } else {
        bool flag = false;
        string s = to_string(n);
        if (n > 0) {
            for (auto it = s.rbegin(); it != s.rend(); ++it) {
                if (*it != '0') {
                    flag = true;
                }
                if (flag) {
                    cout << *it;
                }
            }
        } else {
            cout << s.front();
            for (auto it = s.rbegin(); it != s.rend() - 1; ++it) {
                if (*it != '0') {
                    flag = true;
                }
                if (flag) {
                    cout << *it;
                }
            }
        }
    } cout << endl;

    return 0;
}
