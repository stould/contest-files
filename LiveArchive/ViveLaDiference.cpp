#include <bits/stdc++.h>

using namespace std;

int A, B, C, D;

int main(void) {
  for ( ; cin >> A >> B >> C >> D && A != 0; ) {
    int ans = 0;

    while (true) {
      if (A == B && A == C && A == D) {
	break;
      }
      int aa = abs(A - B);
      int bb = abs(B - C);
      int cc = abs(C - D);
      int dd = abs(D - A);

      A = aa;
      B = bb;
      C = cc;
      D = dd;
      
      ans += 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
