#include <stdio.h>

int i, tmp, n, sum = 0;

int main(void) {
   scanf("%d", &n);
   for(i = 0; i < n; i++) {
   	scanf("%d", &tmp);
   	sum += tmp;
   }
   printf("%d\n", sum);
   return 0;
}
