#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

const double EPS = 1e-9;

int T, N, K;
pair<double, double> P[MAXN];

int check(double rc) {
  int ans = 1, used = 0;
  double sum = 0.0;
  double s = INT_MAX;
  double l = INT_MIN;

  for (int i = 0; i < N; i++) {
    sum += P[i].second;
    used += 1;

    s = min(s, P[i].second);
    l = max(l, P[i].second);
    
    double pos_y = 0;
    
    pos_y = s + (l - s) / 2.0;
    
    //cout << fixed << setprecision(10) << i << " " << rc << " " << ans << " " << pos_y << " " << max(fabs(s - pos_y), fabs(l - pos_y)) << "\n";
      

    if (max(fabs(s - pos_y), fabs(l - pos_y)) - EPS > rc) {
    
      ans += 1;
      
      s = P[i].second;
      l = P[i].second;
      used = 1;
      sum = P[i].second;
    }
  }

  return ans;
}

int main() {
  cin >> T;

  while (T--) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
      cin >> P[i].first;
      cin >> P[i].second;
    }

    sort(P, P + N);

    double l = 0.0, h = 20000000000.0, m;
    double best = 0;

    for (int cnt = 0; cnt < 100; cnt++) {
      m = (l + h) / 2.0;
     
      int used = check(m);
      //cout << used << " " << m << "\n";
      
      if (used <= K) {
	best = m;
	h = m;
      } else {
	l = m;
      }
    }

    cout << fixed << setprecision(1) << best << "\n";
  }
  return 0;
}
