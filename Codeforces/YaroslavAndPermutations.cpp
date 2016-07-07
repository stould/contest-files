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

int N;

int main(void) {
  cin >> N;

  map<int, int> seen;

  bool ok = true;

  if (N != 1) {
    for (int i = 0; i < N; i++) {
      int T;
      cin >> T;
      seen[T] += 1;
      
      if (seen[T] > (N + 1) / 2) ok = false;
    }
  }
  
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
