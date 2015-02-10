#include <bits/stdc++.h>

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;

uInt modPow(uInt a, uInt n, uInt mod) {
  uInt res = 1ULL;
  
  while (n > 0ULL) {
    if (n & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}

uInt inv(uInt x, uInt mod) {
  return modPow(x, mod - 2, mod);
}

Int modPow(Int a, Int n, Int MOD) {
  Int ans = 1LL;
  
  while (n > 0) {
    if (n & 1) {
      ans = (((ans * a) % MOD) + MOD) % MOD;
    }
    a = (((a * a) % MOD) + MOD) % MOD;
    n >>= 1;
  }
  return (ans % MOD);
}

pair<int, pair<int, int> > extendedEuclid(int a, int b) {
  int x = 1, y = 0;
  int xLast = 0, yLast = 1;
  int q, r, m, n;
  while(a != 0) {
    q = b / a;
    r = b % a;
    m = xLast - q * x;
    n = yLast - q * y;
    xLast = x, yLast = y;
    x = m, y = n;
    b = a, a = r;
  }
  return make_pair(b, make_pair(xLast, yLast));
}

Int modInverse(Int a, Int m) {
  return modPow(a, m - 2, m);
  //return (extendedEuclid(a,m).second.first + m) % m;
}

Int totient(Int n) {
  Int result = n;
  
  for(int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      result -= result / i;
    }
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) {
    result -= result / n;
  }
  return result;
}

Int N, E, C;

int main(void) {
  for ( ; cin >> N >> E >> C; ) {
    Int phi = totient(N);
    Int D = inv(E, phi);
    Int M = modPow(C, D, N);
    
    cout << M << "\n";
  }  
  return 0;
}
