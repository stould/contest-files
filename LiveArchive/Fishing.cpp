#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
const int MAX_V = 10010;
const int INF = INT_MAX / 5;

int T;
int N, M;
int P[MAXN][MAXN];
int dp1[MAXN][MAXN][MAXN];
int dp2[MAXN][MAXN][MAXN];

int max_path(int a, int b, int len) {
  if (len == 0) {
    return 0;
  } else if (a >= N || b >= M) {
    return -INF;
  } else {
    int& ans = dp1[a][b][len];
   
    if (ans == -1) {
      ans = P[a][b] + max_path(a + 1, b + 1, len - 1);
      ans = max(ans, max_path(a + 1, b, len));
      ans = max(ans, max_path(a, b + 1, len));
    }
   
    return ans;
  }
}

int min_path(int a, int b, int len) {
  if (len == 0) {
    return 0;
  } else if (a >= N || b >= M) {
    return INF;
  } else {
    int& ans = dp2[a][b][len];
   
    if (ans == -1) {
      ans = INF;
      ans = P[a][b] + min_path(a + 1, b + 1, len - 1);
      ans = min(ans, min_path(a + 1, b, len));
      ans = min(ans, min_path(a, b + 1, len));
    }
   
    return ans;
  }
}

void gen() {
  int t = 10;
  cout << t << "\n";
 
  for (int a = 0; a < t; a++) {
    cout << 100 << " " << 100 << "\n";

    for (int i = 0; i < 100; i++) {
      for (int j= 0; j < 100; j++) {
    cout << rand() % 1000 << " ";
      }
      cout << "\n";
    }
  }
}

int main() {
  //gen();
  //return 0;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
    cin >> P[i][j];
   
    for (int k = 0; k < MAXN; k++) {
      dp1[i][j][k] = dp2[i][j][k] = -1;
    }
      }
    }   

    int ans = 0;

    for (int m = 1; m <= N / 2; m++) {     
      int pa = max_path(0, 0, m);
      int pb = min_path(0, 0, 2 * m);
     
      //cout << m << " " << pa << " " << pb << "\n";
      int profit = max(0, pa - pb);
     
      if (profit > ans) {
    ans = profit;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
