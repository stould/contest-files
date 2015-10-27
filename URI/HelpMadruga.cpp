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
const double EPS = 1e-8;

int N;
double A;
int P[MAXN];

bool eq(double a, double b) {
	return fabs(a - b) < EPS;
}

int main(void) {
	for ( ; cin >> N >> A; ) {
		if (N == 0 && A == 0) {
			break;
		}

		int highest = 0;
		double l = 0.0, h = 100000.0, m;
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			highest = max(highest, P[i]);
		}
		
		for (int x = 0; x < 250; x++) {
			m = (l + h) / 2;

			double area = 0.0;
			
			for (int i = 0; i < N; i++) {
				area += max(0.0, P[i] - m);
			}

			if (area >= A) {
				l = m;
			} else {
				h = m;
			}
		}

		double area = 0.0;
		
		for (int i = 0; i < N; i++) {
			area += max(0.0, P[i] - m);
		}
		
		if (eq(area, A)) {
			if (eq(m, 0)) {
				cout << ":D\n";
			} else {
				cout << fixed << setprecision(4) << m << "\n";
			}
		} else {
			cout << "-.-\n";
		}
	}
	return 0;
}
