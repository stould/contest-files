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

const int MAXN = 100005;

int N, Q;
Int P[MAXN];
Int tree[3][MAXN];

void add(int tr, int id, Int val) {
  while (id <= N + 1) {
    tree[tr][id] += val;
    id += (id & -id);
  }
}

Int get(int tr, int id) {
  Int ans = 0;
  
  while (id > 0) {
    ans += tree[tr][id];
    id -= (id & -id);
  }

  return ans;
}

Int interval(int tr, int l, int r) {
  if (l > r) return 0;

  return get(tr, r) - get(tr, l - 1);
}

int main(void) {
  cin >> N >> Q;

  for (int i = 1; i <= N; i++) {
    cin >> P[i];
    
    add(0, i, P[i]);
    add(1, i, P[i] * i);
    add(2, i, P[i] * (N - i));
  }

  for ( ; Q--; ) {
    int T;
    
    cin >> T;
    
    if (T == 1) {
      int K, L, R;
      
      cin >> K >> L >> R;

      Int ans = 0;

      if (L <= K && R >= K) {
        Int sa = 0, sb = 0;
        Int ia = 0, ib = 0;
        sa += interval(1, L, K - 1);
        sb += interval(2, K + 1, R);
        
        ia += K * interval(0, L, K - 1);
        ib += (Int) (N - K) * interval(0, K + 1, R);

        ans += abs(sa - ia);
        ans += abs(sb - ib);
      } else {
        Int sum = 0LL;
        Int ins = interval(0, L, R);
        
        if (K <= L) {
          sum += interval(1, L, R);
          ins *= (Int) K;
        } else {
          sum += interval(2, L, R);
          ins *= (Int) (N - K);
        }
        ans += abs(sum - ins);
      }
      
      cout << ans << "\n";
    } else {
      int K;
      Int S;
      
      cin >> K >> S;
      
      add(0, K, S);
      add(1, K, S * K);
      add(2, K, (N - K) * S);
    }
  }
  
  return 0;
}
