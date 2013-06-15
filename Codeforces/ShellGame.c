#include <stdio.h>
#include <stdlib.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ball, a, b;

    scanf("%d", &ball);

    int t = 3;

    while(t > 0) {
        scanf("%d %d", &a, &b);
        t--;
        if(ball == a) { ball = b; continue; }
        if(ball == b) { ball = a; continue; }
    }

    printf("%d", ball);

    return 0;
}
