#include <bits/stdc++.h>

using namespace std;

int T;
int P, B, X, Y;

vector<int> conv(int value, int base) {
  vector<int> ans;
  while (value > 0) {
    ans.push_back(value % base);
    value /= base;
  }
  return ans;
}

int main(void) {
  cin >> T;
  
  for ( ; T--; ) {
    cin >> P >> B >> X >> Y;
    
    vector<int> xB = conv(X, B);
    vector<int> yB = conv(Y, B);

    while (xB.size() < yB.size()) {
      xB.push_back(0);
    }
    
    while (yB.size() < xB.size()) {
      yB.push_back(0);
    }
    
    int size = xB.size();
	
    long long ans = 0LL;
    long long power = 1LL;

    for (int i = 0; i < size; i++) {
      long long v = (xB[i] + yB[i]) % B;
      ans += v * power;
      power *= B;
    }

    cout << P << " " << ans << "\n";
  }
  return 0;
}
