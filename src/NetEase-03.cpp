#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int length = 1, tmp_length = 1;
    for (size_t i = 0; i < s.size() - 1; ++i) {
        if (s[i] != s[i + 1]) {
            ++tmp_length;
            if (length < tmp_length) {
                length = tmp_length;
            }
        } else {
            tmp_length = 1;
        }
    } cout << length << endl;

    return 0;
}
