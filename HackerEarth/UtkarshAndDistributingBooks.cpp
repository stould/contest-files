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

const int MAXN = 1010;

int T, N, K;
int P[MAXN];

int main(void) {
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> N;

    int S = 0;
    int A = 0;
    int B = 0;
    
    for (int i = 0; i < N; i++) {
      cin >> P[i];
      S += P[i];
    }

    sort(P, P + N);

    A = P[0] - 1;
    B += N + (S - 2 * N);

    cout << A << " " << B << "\n";
  }
  return 0;
}
