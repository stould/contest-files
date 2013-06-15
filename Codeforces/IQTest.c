#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int values[101];

int main(void) {
    int i, j, N;

    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    for(i = 0; i < N; i++) {
        int ok = 1;
        for(j = 0; j < N; j++) {
            if(i != j && abs(values[i] - values[j]) % 2 == 0) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            printf("%d\n", (i + 1));
            break;
        }
    }
    return 0;
}
