#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a > b ? b : a;
}

int main(void) {
    int N, i, a, b, c, high, mid, low;

    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        scanf("%d%d%d", &a, &b, &c);

        high = max(a, max(b, c));
        low = min(a, min(b, c));
        mid = high == a ? max(b, c) : high == b ? max(a, c) : max(a, b);

        if((low * low) + mid * mid == high * high) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}



