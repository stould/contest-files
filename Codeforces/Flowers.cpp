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

const int MAXN = 100005;
const int MOD = 1000000007;

int T, K;
int A, B;

Int dp[MAXN], sum[MAXN];

Int func(int id) {
  if (id < 0) {
    return 0;
  } else if (id == 0) {
    return 1;
  } else {
    Int& ans = dp[id];

    if (ans == -1) {
      ans = func(id - 1);

      ans = (ans + func(id - K)) % MOD;
    }

    return ans;
  }
}

int main(void) {
  cin >> T >> K;

  memset(dp, -1, sizeof(dp));

  sum[0] = 0LL;
  
  for (int i = 1; i <= 100000; i++) {
    sum[i] = sum[i - 1] + func(i);
  }

  for ( ; T--; ) {
    cin >> A >> B;

    Int ans = sum[B] - sum[A - 1];
    
    cout << ans % MOD << "\n";
  }
  
  return 0;
}
