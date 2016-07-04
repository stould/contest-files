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

const int MAXN = 10005;

int N, M, K;
int P[MAXN], L[MAXN], R[MAXN], D[MAXN], S[MAXN];
int seen[MAXN];

int main(void) {
  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) {
    cin >> P[i];
  }
  
  for (int i = 1; i <= M; i++) {
    cin >> L[i] >> R[i] >> D[i];
  }

  for (int i = 1; i <= K; i++) {
    int X, Y;
    cin >> X >> Y;

    S[X] += 1;
    S[Y + 1] -= 1;
  }
  
  Int sc = 0LL;

  for (int i = 1; i <= M; i++) {
    sc += S[i];
    seen[L[i]] += D[i] * sc;
    seen[R[i] + 1] -= D[i] * sc;
  }
  
  sc = 0LL;
  
  for (int i = 1; i <= N; i++) {
    sc += seen[i];

    cout << P[i] + sc << " ";
  }

  cout << endl;
  
  return 0;
}
