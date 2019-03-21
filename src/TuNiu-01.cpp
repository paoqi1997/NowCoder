#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s, ss;
    cin >> s >> ss;

    size_t len = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        for (size_t j = 1; j <= s.length() - i; ++j) {
            string _s = s.substr(i, j);
            if (ss.find(_s) != string::npos) {
                len = max(len, _s.length());
            }
        }
    } cout << len << endl;

    return 0;
}
