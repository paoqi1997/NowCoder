#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long x, f, d, p;
    cin >> x >> f >> d >> p;

    int day = min(d / x, (d + f * p) / (x + p));
    cout << day << endl;

    return 0;
}
