#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int n, i, outcome_a, outcome_b, t = 1;
char name_a[11], name_b[11];

int main(void) {
  /*  freopen("i.in", "r", stdin); */
    while(scanf("%d", &n) && n > 0) {
        scanf("%s %s", name_a, name_b);
        int sum_a = 0, sum_b = 0;
        printf("Teste %d\n", (t++));
        for(i = 0; i < n; i++) {
            scanf("%d %d", &outcome_a, &outcome_b);
            int aux = outcome_a + outcome_b;
            if(aux % 2 == 0) {
                printf("%s\n", name_a);
            } else {
                printf("%s\n", name_b);
            }
        }
        printf("\n");
    }
    return 0;
}
