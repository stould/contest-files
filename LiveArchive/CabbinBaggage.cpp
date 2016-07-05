#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;
int T;

int main() {
  cin >> T;
  
  int ans = 0;
  double L, W, D, Wei;

  for (int i = 0; i < T; i++) {
    cin >> L >> W >> D >> Wei;
    
    L -= EPS;
    W -= EPS;
    D -= EPS;
    Wei -= EPS;

    if (((L <= 56.0 && W <= 45.0 && D <= 25.0) || L + W + D <= 125.0) && Wei <= 7.0) {
      ans += 1;
      cout << 1 << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}
