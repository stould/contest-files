#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int d, i, j, v[50], sub[1100], t = 1;

bool subsetSum(int n, int g) {
    for(j = 0; j <= g; j++) sub[j] = 0;
    sub[0] = 1;
    for(j = 0; j < n; j++) if(v[j] != g) {
        for(int k = g; k >= v[j]; k--) {
            sub[k] |= sub[k - v[j]];
        }
    }
    return sub[g];
}

int main(void) {
    freopen("i.in", "r", stdin);
    bool already = false;
    while(~scanf("%d", &d)) {
        bool has = false;
        if(already) {
            printf("\n");
        }
        already = true;
        for(i = 0; i < d; i++) {
            scanf("%d", &v[i]);
            if(i == 0) continue;
            if(!has) {
                if(subsetSum(i, v[i])) has = true;
            }
        }
        printf("Case #%d: ", t++);
        for(i = 0; i < d; i++) {
            if(i == d - 1) {
                printf("%d\n", v[i]);
            } else {
                printf("%d ", v[i]);
            }
        }
        bool is = true;
        for(int i = 1; i < d; i++) {
            if(v[i - 1] > v[i]) is = false;
        }
        if(is && !has) {
            printf("This is an A-sequence.");
        } else {
            printf("This is not an A-sequence.");
        }
    }
    return 0;
}
