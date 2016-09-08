#include <stdio.h>
 
int c, m, i, n, index, max, len, mem[1010], test = 1;
 
int main(void) {
    while(scanf("%d", &n) && n != 0) {
        max = 0, len = 0;
        for(i = 0; i < n; i++) {
            scanf("%d%d", &c, &m);
            if(m == max) {
                mem[len++] = c;
            } else if(m > max) {
                max = m; len = 0;
                mem[len++] = c;
            }
        }
        printf("Turma %d\n", test++);
        for(i = 0; i < len; i++) {
            printf("%d ", mem[i]);
        }
        printf("\n\n");
    }
    return 0;
}
 
 
