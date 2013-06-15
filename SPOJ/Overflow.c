#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, p, q, all;
char c;

int main(void) {
  scanf("%d%d %c%d", &n, &p, &c, &q);
  if(c == '*') {
    all = p * q;
  } else {
    all = p + q;
  }
  if(all <= n) {
    printf("OK\n");
  } else {
    printf("OVERFLOW\n");
  }
  return 0;
}
