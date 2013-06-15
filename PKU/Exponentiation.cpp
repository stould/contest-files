#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ld r;
ll n;

int main(void) {
    while(cin >> r >> n) {
        ld ans = r;
        for(int i = 0; i < n; i++) {
            ans = ans * ld(r);
        }
        ll tmp = ll(r);
        cout << ans << endl;
        if(tmp == r) {
        } else {

        }
    }
    return 0;
}
