#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll n, v[2000010];

int main(void) {
    while(scanf("%ld", &n) && n > 0) {
        for(ll i = 0L; i < n; i += 1L) {
            scanf("%ld", &v[i]);
        }
        ll ans = 0L;
        sort(v, v + n);
        for(int i = 0, j = n - 1; i < j; i++, j--) {
            ll sum =  v[i] + v[j];
            if(sum > ans) {
                ans = sum;
            }
        }
        printf("%ld\n", ans);
    }
    return 0;
}
