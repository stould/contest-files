#include <iostream>

using namespace std;

typedef long long ll;

int w, h;
ll ans = 0;

int main(void) {
    cin >> w >> h;

    for(int i = 2; i <= h ; i += 2) {
        for(int j = 2; j <= w; j += 2) {
            ans += (h - i + 1) * (w - j + 1);
        }
    }

    cout << ans << endl;

    return 0;
}
