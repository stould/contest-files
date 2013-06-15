#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll n, k, t;

int main(void) {
    scanf("%ld%ld%ld", &n, &k, &t);
    for(ll x = 0; ; x++) {
        if((x*100) <= (n*k*t) && (n*k*t) < ((x + 1)*100)) {
            vector<ll> ans(n, 0);
            for(ll i = 0; i < (x / k); i++) {
                ans[i] = k;
            }
            ans[x/k] = (x - (x/k)*k);
            for(int i = 0; i < ans.size(); i++) {
                if(i == ans.size() - 1) {
                    printf("%d\n", ans[i]);
                } else {
                    printf("%d ", ans[i]);
                }
            }
            return 0;
        }
    }
    return 0;
}
