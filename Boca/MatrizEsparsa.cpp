#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

int t, n;

int main(void) {
  cin >> t;

  while(t--) {
    cin >> n;
    
    Int sq = n*n;
    
    char ans = (sq/2 > (2*(n-1) + n) ? 'S' : 'N');

    cout << ans << " " << sq - (2*(n-1) + n) << "\n";
  }

  return 0;
}
