#include <stdio.h>

#define MAXN 55

int N;
int buf[MAXN];

int main(void) {
    int i, test = 1;

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        int ans = 0, med = 0;

        for (i = 0; i < N; i++) {
            scanf("%d", &buf[i]);
            med += buf[i];
        }

        med /= N;

        for (i = 0; i < N; i++) {
            if (buf[i] < med) ans += med - buf[i];
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", test++, ans);
    }
    return 0;
}
