#include <iostream>

using namespace std;

typedef long long ll;

ll n, p, q, r, s, x, y, ni, nj, ans = 0;

int main(void) {
    for ( ; cin >> n >> p >> q >> r >> s >> x >> y >> ni >> nj;  ) {
        ans = 0LL;
        for(int z = 1; z <= n; z++) {
            ans += (ll) ((p*ni + q*z)%x) * ((r*z + s*nj)%y);
        }
        cout << ans << endl;
    }
    return 0;
}
