#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    size_t preIndex = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            cout << s[preIndex];
            preIndex = i + 1;
        }
    } cout << s[preIndex] << endl;

    return 0;
}
