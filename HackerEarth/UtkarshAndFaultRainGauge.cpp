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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1005;

int T;
int N[MAXN], R[MAXN];
double dp[MAXN];
bool seen[MAXN];

double func(int pos) {
  if (pos == T) {
    return 1;
  } else {
    double& ans = dp[pos];

    if (!seen[pos]) {
      seen[pos] = true;

      double prob = 0.0;
      
      for (int i = 1; i <= N[pos]; i++) {
        prob += i / (double) R[pos];
        cout << fixed << setprecision(1) << pos << " " << i << " " << prob << endl;
        
        ans += prob * (i / (double) R[pos]) * func(pos + 1);
      }
    }
    
    return ans;
  }
}

int main(void) {
  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N[i] >> R[i];    
  }

  double ans = func(0);

  cout << fixed << setprecision(4) << ans << "\n";
  return 0;
}
