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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N, Q;
int P[MAXN];
int dp[MAXN][50];

void build() {
  int pw = 1;
  int base = 1;

  for (int i = 0; i < N; i++) {
    dp[i][0] = i;
  }
  
  while (base < N) {
    for (int i = 0; i + base < N; i++) {
      int before = base / 2;
      
      if (P[dp[i][pw - 1]] <= P[dp[i + base - before][pw - 1]]) {
        dp[i][pw] = dp[i][pw - 1];
      } else {
        dp[i][pw] = dp[i + base - before][pw - 1];
      }
    }
    
    pw += 1;
    base *= 2;
  }
}

int query(int l, int r) {
  int len = r - l + 1;

  if (len == 1) return P[dp[l][0]];
  
  int ps = 1;
  
  while (l + 2 * ps <= r) {
    ps *= 2;
  }

  int a = dp[l][ps];
  int b = dp[r - ps][ps];

  return min(P[a], P[b]);
}

int main(void) {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }

  build();

  cin >> Q;

  for ( ; Q--; ) {
    int A, B;

    cin >> A >> B;

        
    cout << query(A, B) << "\n";
  }
  return 0;
}
