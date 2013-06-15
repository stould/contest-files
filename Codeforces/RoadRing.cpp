#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)

int a, b, c, n;

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d%d", &a, &b, &c);
    }
    return 0;
}
