#include <stdio.h>
#include <math.h>

#define MAXN 1010

int N;
char str[MAXN];

int main(void) {
  int i, j;

  scanf("%d%s", &N, str);

  int ans = MAXN + 20;
  int H = 0;

  for (i = 0; i < N; i++) {
    if (str[i] == 'H') {
      H += 1;
    }
  }

  for (i = 0; i < N; i++) {
    int curr = 0;
    for (j = 0; j < H; j++) {
      curr += (str[(i + j) % N] != 'H');
    }
    if (curr < ans) {
      ans = curr;
    }
  }

  printf("%d\n", ans);

  return 0;
}
