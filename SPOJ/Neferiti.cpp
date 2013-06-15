#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

typedef long long ll;

int i, j, k, n, t, mem[110];

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> t;
    for(i = 0; i < t; i++) {
        cin >> n >> k;
        for(j = 0; j < n; j++) {
            mem[j] = j;
        }
        ll ans = 0;
        do {
            bool ok =true;
            for(j = 0; j < n; j++) {
                if(fabs(mem[j] - j) > k) {
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        } while(next_permutation(mem, mem + n));
        cout << ans << endl;
    }
    return 0;
}
