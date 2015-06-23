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

const double EPS = 1e-6;
const double INF = 1e20;
const int ITER = 80;
const int MAXN = 110;

int T, N;
double R[MAXN], C[MAXN], V, X;

bool eq(double x, double y) {
	return fabs(x - y) < EPS;
}

double bsA() {
	double l = 0.0, h = V, m;
	double ans = INF;
	
	for (int i = 0; i < ITER; i++) {
		m = (l + h) / 2.0;
		
		double volA = m;
		double tA = C[0];
		
		double volB = V - volA;
		double tB = C[1];
		
		double tempC = (volA * tA + volB * tB) / V;
		
		//cout << l << " " << m << " " << h << "\n";
		cout << volA << " " << volB <<" \n";
		cout << volA / R[0] + volB / R[1] << " " << tempC << " - " << X << "\n";
		
		if (tempC < X) {
			if (C[1] > C[0]) {
				l = m;
			} else {
				h = m;
			}
		} else {
			if (C[1] > C[0]) {
				h = m;
			} else {
				l = m;
			}
		}
	}
	return ans;
}

double bsB() {
	double l = 0.0, h = V, m;
	double ans = INF;
	
	for (int i = 0; i < ITER; i++) {
		m = (l + h) / 2.0;
		
		double volA = m;
		double tA = C[1];
		
		double volB = V - volA;
		double tB = C[0];
		
		double tempC = (volA * tA + volB * tB) / V;
		
		if (eq(tempC, X)) {
			ans = volA / R[1] + volB / R[0];
		} else if (tempC - EPS < X) {
			if (C[1] > C[0]) {
				l = m;
			} else {
				h = m;
			}
		} else {
			if (C[1] > C[0]) {
				h = m;
			} else {
				l = m;
			}
		}
	}
	return ans;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> V >> X;

		for (int i = 0; i < N; i++) {
			cin >> R[i] >> C[i];
		}
		cout << "Case #" << t << ": ";

		if (N == 1) {
			if (eq(X, C[0])) {
				cout << fixed << setprecision(6) << V / R[0] << "\n";
			} else {
				cout << "IMPOSSIBLE\n";
			}
		} else {
			if (C[1] > C[0]) {
				swap(C[0], C[1]);
				swap(R[0], R[1]);
			}
			double a = bsA();
			double b = bsB();

			cout << a << " " << b << "\n";
			
			double ans = min(a, b);

			if (ans >= INF) {
				cout << "IMPOSSIBLE\n";
			} else {
				cout << fixed << setprecision(8) << ans << "\n";
			}
		}
	}
	return 0;
}
