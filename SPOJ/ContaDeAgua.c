#include <stdlib.h>
#include <stdio.h>

int main() {
    int N, i, total = 7;

    scanf("%d", &N);

    //Worst-Case O(N - 11)
    for(i = 11; i <= N; i++) {
        if(i >= 11 && i <= 30) total += 1;
        if(i >= 31 && i <= 100) total += 2;
        if(i > 100) total += 5;
    }

    printf("%d", total);

    return 0;
}
