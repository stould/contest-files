#include <stdio.h>
 
int n, a = 1;
 
int main(void) {
    while(scanf("%d", &n) && n > 0) {
        printf("Teste %d\n%d\n\n", a++, (1 << n) - 1);
    }
    return 0;
}
 
 
