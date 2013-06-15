#include <stdio.h>

int main() {
    freopen("i.in", "w", stdout);
    printf("%d\n", 200000);
    for(int i = 1; i <= 20000; i++) {
        printf("%d ", i);
    }
    return 0;
}
