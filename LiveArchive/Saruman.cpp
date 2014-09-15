 #include <bits/stdc++.h>

using namespace std;

const int MAXS = 20020;
const int INF = INT_MAX / 3;

int T, N, K;
char S[MAXS];

int main(void) {
  scanf("%d", &T);

  for ( ; T--; ) {
    scanf("%d%d%s", &N, &K, S);
   
    int ans = 0;
    bool valid = false;

    for (int i = 0; i < N; i++) {
      int j = i;

      for ( ; j < N && S[i] == S[j]; ) {
    if (j - i + 1 >= K) {
      valid = true;
    }
    j += 1;
      }

      int len = j - i;

      ans += len / K;

      if ((len % K) != 0) {
    ans += 1;
      }

      i = j - 1;
    }

    if (!valid) {
      puts("-1");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
