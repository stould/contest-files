#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

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

const int MAXN = 10010;

int N, Q;

int main(void) {
  int i;
  int T = 1;
  
  for ( ; scanf("%d%d", &N, &Q) == 2 && N + Q != 0; ) {
    vector<int> x(N);

    for (i = 0; i < N; i++) {
      x[i] = in();
    }

    sort(x.begin(), x.end());

    printf("CASE# %d:\n", T++);

    for ( ; Q--; ) {
      int P = in();

      vector<int>::iterator it = lower_bound(x.begin(), x.end(), P);

      if (it == x.end() || *it != P) {
	printf("%d not found\n", P);
      } else {
	printf("%d found at %d\n", P, (int) (it - x.begin() + 1));
      }
    }
  }

  return 0;
}
