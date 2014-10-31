#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 55;
const double INF = 100101010010.0;
const double EPS = 1e-7;

int N, M;
int X[MAXN], Y[MAXN];
double dst[MAXN][MAXN];
bool has[MAXN][MAXN];

int main(void) {
  for ( ; scanf("%d%d", &N, &M) == 2 && !(N == 0 && M == 0); ) {
    int u, v;

    for (int i = 1; i <= N; i++) {
      scanf("%d%d", &X[i], &Y[i]);
     
      for (int j = 1; j <= i; j++) {
    dst[i][j] = dst[j][i] = INF;
    has[i][j] = has[j][i] = false;
      }
      dst[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
      scanf("%d%d", &u, &v);

      double d = hypot(X[u] - X[v], Y[u] - Y[v]);

      has[u][v] = has[v][u] = true;     

      chmin(dst[u][v], d);
      chmin(dst[v][u], d);
    }
   
    for (int k = 1; k <= N; k++) {
      for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      chmin(dst[i][j], dst[i][k] + dst[k][j]);
    }
      }
    }

    double df = 0.0;
    double actual_df = INF;

    int a = -1, b = -1;
   
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {      
    if (!has[i][j]) {
      double d = hypot(X[i] - X[j], Y[i] - Y[j]);
      double now = 0.0;
     
      for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= N; v++) {
          double curr = dst[u][v];
         
          chmin(curr, dst[u][i] + d + dst[j][v]);
          chmin(curr, dst[u][j] + d + dst[i][v]);

          now += dst[u][v] - curr;
        }
      }

      //      cout << i << " " << j << " " << now << "\n";
     
      if (now >= 1.0 && (now > df || (fabs(now - df) < EPS && d < actual_df))) {
        df = now;
        actual_df = d;
        a = i;
        b = j;
      }
    }
      }
    }
   
    if (a != -1) {
      printf("%d %d\n", a, b);
    } else {
      printf("No road required\n");
    }
  }
  return 0;
}
