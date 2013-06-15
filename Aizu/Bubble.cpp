#include <stdio.h>

int i, j, n, v[110];

int main(void) {
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int swaps = 0;
    for(i = 0; i <= n; i++) {
        for(j = n; j >= i + 1; j--) {
            if(v[j] < v[j - 1]) {
                swaps++;
                int tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
            }
        }
    }
    for(i = 1; i <=  n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n%d\n", swaps);
}
