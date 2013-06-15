#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int N, a, b, i, values[101], years = 0;

    scanf("%d", &N);

    for(i = 0; i < N - 1; i++) {
        scanf("%d", &values[i]);
    }
    scanf("%d %d", &a, &b);

    a -= 1;
    b -= 1;

    while(a < b) {
        years += values[a];
        a++;
    }

    printf("%d", years);

    return 0;
}
