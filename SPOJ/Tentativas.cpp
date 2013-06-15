#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, v[8];

int main(void) {
    while(~scanf("%d", &n) && n > 0) {
        for(int i = 0; i < n; i++) scanf("%d", &v[i]);
        sort(v, v + n);
        do {
            for(int i = 0; i < n; i++) {
                if(i == n - 1) {
                    printf("%d\n", v[i]);
                } else {
                    printf("%d ", v[i]);
                }
            }
            printf("\n");
        } while(next_permutation(v, v + n));
    }
    return 0;
}
