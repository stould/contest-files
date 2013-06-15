#include <iostream>

using namespace std;

int a, b, c;

int main(void) {
    cin >> a >> b >> c;
    int ans = 0;

    while((ans + c) * b < a * c) ans += 1;

    cout << ans << endl;

    return 0;
}
