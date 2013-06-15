#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void) {
    int ball, a, b;

    scanf("%d", &ball);

    int t = 3;

    while(t > 0) {
        scanf("%d %d", &a, &b);
        if(ball == a) { ball = b; }
        if(ball == b) { ball = a; }
        t--;
    }
    printf("%d", ball);

    return 0;
}
