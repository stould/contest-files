#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int (i) = 0; (i) < (n); i++)
#define MOD 100000000

int n, v;
ll ans;

ll func(int x) {
  ll f = 1LL, base = 0;
  REP(i, x) {
    cout << ((1 << base) % MOD) << " ";
    f += (ll) ((1 << (base++)) % MOD);
  }
  cout << "\n";
  return f;
}

int main(void) {
  cin >> n;
  REP(i, n) {
    cin >> v;
    cout << ll(func(v)/12.0/1000.0) << " kg\n";
  }
  return 0;
}
