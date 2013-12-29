#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <math.h>

#define REP(i, n) for(i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const int MOD = 1300031;
ll i, j, inst, n, ans, helper, mem[100010];

int main(void) {
    scanf("%lld", &inst);
    for( ; inst > 0; inst--) {
        ans = 0L; helper = 0;
        scanf("%lld", &n);
        REP(i, n) {
            scanf("%lld", &mem[i]);
            ans += (ll) ((mem[i] * mem[i]) % MOD) % MOD;
            ans += (ll) ((helper * mem[i]) % MOD) % MOD;
            helper += (mem[i] % MOD);
        }
        printf("%lld\n", ans % MOD);
    }
    return 0;
}



