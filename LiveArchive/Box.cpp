#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int T;
int N, M;
int P[MAXN][MAXN];

int main() {
  cin >> T;

  while (T--) {
    cin >> N >> M;

    for (int i= 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	cin >> P[i][j];
      }
    }
    
    int ans = 0;

    for (int i = N - 1; i >= 0; i--) {
      for (int j = 0; j < M; j++) {
	int k = i;

	while (k + 1 < N && P[k][j] == 1 && P[k + 1][j] == 0) {
	  swap(P[k][j], P[k + 1][j]);
	  ans += 1;
	  k++;
	}
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
