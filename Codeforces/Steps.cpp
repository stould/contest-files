#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll n, m, x, y, k, dx, dy, steps = 0L;


const ll INF = 1 << 30;

int main(void) {
    cin >> n >> m >> x >> y >> k;

    for(ll i = 0; i < k; i++) {
        cin >> dx >> dy;
        ll low = 0, high = INF, mid;
        while(low + 1 < high) {
            mid = (low + high) / 2;
            ll xa = x + (mid * dx);
            ll ya = y + (mid * dy);

            if(xa < 1 || ya < 1 || xa > n || ya > m) {
                high = mid;
            } else {
                low = mid;
            }
        }
        x += (low * dx);
        y += (low * dy);
        steps += low;
    }
    cout << steps << endl;
    return 0;
}

