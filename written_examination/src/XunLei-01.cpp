#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s = "1";
    for (int i = 1; i <= n; ++i) {
        int carry = 0;
        for (size_t j = 0; j < s.length(); ++j) {
            int cnt = (s[j] - '0') * 2;
            // 追加上一位的进位
            cnt += carry;
            // 获取这一位的进位
            carry = cnt / 10;
            // 结算
            s[j] = cnt % 10 + '0';
            if (j == s.length() - 1 && carry > 0) {
                s.push_back(carry + '0');
                break;
            }
        }
    }

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it;
    }
    cout << endl;

    return 0;
}
