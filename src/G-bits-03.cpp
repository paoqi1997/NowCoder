#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    sort(s.begin(), s.end(), [](char x, char y) {
        if (islower(x) && isdigit(y)) {
            return true;
        } else if (isdigit(x) && islower(y)) {
            return false;
        } else {
            return x < y;
        }
    });

    cout << s << endl;

    return 0;
}
