#include <bits/stdc++.h>

using namespace std;

int T, N, B;
long long dp[70][15];

long long func(int pos, int last) {
  if (pos == 0) {
    return 1LL;
  } else {    
    long long& ans = dp[pos][last];
    
    if (ans == -1LL) {
      ans = 0LL;
      for (int i = last; i >= 0; i--) {
	ans += func(pos - 1, i);
      }
    }
    
    return ans;
  }
}

int main(void) {
  cin >> T;

  for ( ; T--; ) {
    cin >> B >> N;
    memset(dp, -1, sizeof(dp));
    cout << B << " " << func(N, 9) << "\n";
  }
  return 0;
}
