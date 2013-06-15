#include <stdlib.h>
#include <stdio.h>

int main() {
    int n, a, b, ans = 0;

    scanf("%d %d %d", &n, &a, &b);

    if(a + b >= n - 1) {
        ans = n - a;
    } else {
        ans = b + 1;
    }

    printf("%d", ans);

    return 0;
}
