#include <iostream>

using namespace std;

typedef long long ll;

ll x, y;

int main(void) {
    cin >> x >> y;

    ll ans = 0;

    for(; x <= 10; x++) ans++;
    if(y >= 100) { ans += 9; x = 100; }
    for(; x <= y; x += 100) {

    }
    cout << ans << end;

    return 0;
}
