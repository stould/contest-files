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

// print array
template <typename T>
ostream& operator<<(ostream &out, const vector<T> &list) {
  out << "[";
  for (int i = 0; i < (int)list.size(); ++i) {
    if (i > 0) out << ", ";
    out << list[i];
  }
  out << "]";
  return out;
}

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int D, L, V1, V2;

int main(void) {
	cin >> D >> L >> V1 >> V2;

	double l = 0, h = 1000000, m;
	
	for (int i = 0; i < 300; i++) {
		m = (l + h) / 2;
		
		if (V1 * m + D <= L - m * V2) {
			l = m;
		} else {
			h = m;
		}
	}

	cout << fixed << setprecision(6) << m << endl;
	
	return 0;
}
