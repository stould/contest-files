#include <iostream>

using namespace std;

int n, ans = 0;

int main(void) {
    cin >> n;
    int a = n, b = n;

    ans += (b / 2); b /= 2;
    ans += (a / 2); a /= 2;
    ans += (b);

    cout << ans << endl;

    return 0;
}
