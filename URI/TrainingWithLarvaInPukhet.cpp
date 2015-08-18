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
typedef unsigned uint;

const int MAXN = 20003;
const double EPS = 1e-6;
const double INF = 100100110000.0;

int T, N;

double area(double a, double b, double c) {
	double s = (a + b + c) / 2.0;

	double area = sqrt(s * (s - a) * (s - b) * (s - c));

	return area;
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N;

		vector<double> P(N);

		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		sort(P.begin(), P.end());

		double ans = INF;
		
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				vector<double>::iterator it = lower_bound(P.begin() + j, P.end(), P[i] + P[j]);
				it--;				
				if ((it - P.begin()) != j) {
					if (P[i] + P[j] > (*it)) {
						cout << P[i] << " " << P[j] << " " << (*it) << "\n";
						ans = min(ans, area(P[i], P[j], (*it)));
					}					
				}					
			}
		}
		//cout << fixed << setprecision(2) << ans << " " << brute_ans << "\n";
		if (ans >= INF) {
			cout << "-1\n";
		} else {
			cout << fixed << setprecision(2) << ans << "\n";
		}
	}
	return 0;
}
