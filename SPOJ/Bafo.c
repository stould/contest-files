#include <stdio.h>

int i, n, ta, tb, sa, sb, t = 1;

int main(void) {
    while(scanf("%d", &n) && n > 0) {
        sa = sb = 0;
        for(i = 0; i < n; i++) {
            scanf("%d %d", &ta, &tb);
            sa += ta;
            sb += tb;
        }
        printf("Teste %d\n", t++);
        if(sa > sb) {
            printf("Aldo\n");
        } else{
            printf("Beto\n");
        }
        printf("\n");
    }
    return 0;
}
