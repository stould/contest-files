#include <stdio.h>

int hill[10];

int main(void) {
    int i, j;
    for(i = 0; i < 10; i++) {
        scanf("%d", &hill[i]);
    }

    for(i = 1; i < 10; i++) {
        int a = i;
        int b = hill[i];

        while(a > 0 && hill[a - 1] > b) {
            hill[a] = hill[a - 1];
            a--;
        }
        hill[a] = b;
    }

    for(i = 9; i >= 7; i--) {
        printf("%d\n", hill[i]);
    }

    return 0;
}

