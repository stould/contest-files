#include <bits/stdc++.h>

using namespace std;

int N, P[50];
char S[50][50];

int main(void) {
  for ( ; scanf("%d", &N) == 1 && N != -1; ) {
    int A, B, C;
    int p = 100101010, g = -1;
    for (int i = 0; i < N; i++) {
      scanf("%d%d%d%s", &A, &B, &C, S[i]);
      P[i] = A * B * C;
      p = min(p, P[i]);
      g = max(g, P[i]);
    }

    bool ok = false;

    for (int i = 0; !ok && i < N; i++) {
      for (int j = 0; !ok && j < N; j++) {
	if (i != j && P[i] == g && P[j] == p) {
	  printf("%s took clay from %s.\n", S[i], S[j]);
	  ok = true;
	}
      }
    }
  }
  return 0;
}
