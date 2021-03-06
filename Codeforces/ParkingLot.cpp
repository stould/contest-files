#include <stdio.h>
#include <string.h>

#define MAXN 100009

int L, b, f, N;
int used[MAXN];

int kind, ag;

int id[110][2];

int func1(int identify, int len) {
  int i, j;

  for (i = 0; i <= L - len; i++) if (!used[i]) {
    int empty = 0;

    for (j = -b; j < len + f; j++) if (i + j >= 0) {
      empty |= (used[i + j] != 0);
    }

    if (!empty) {
      for (j = 0; j < len; j++) {
	used[i + j] = 1;
      }
      id[identify][0] = i;
      id[identify][1] = len;
      return i;
    }
  }
  return -1;
}

void func2(int identify) {
  int i;

  for (i = id[identify][0]; i < id[identify][0] + id[identify][1]; i++) {
    used[i] = 0;
  }
}

int main(void) {
  scanf("%d%d%d%d", &L, &b, &f, &N);

  int i;

  memset(used, 0, sizeof(used));

  for (i = 0; i < N; i++) {
    scanf("%d%d", &kind, &ag);

    if (kind == 1) {
      printf("%d\n", func1(i, ag));
    } else {
      func2(ag - 1);
    }
  }
  return 0;
}
