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

const int MAXN = 2002;
const double PI = acos(-1.0);
const double EPS = 1e-7;

int T, N;
double X[MAXN], Y[MAXN];

double rotatedX(double x, double y) {
	return x * cos(60 * PI / 180) - y * sin(60 * PI / 180);
}

double rotatedY(double x, double y) {
	return x * sin(60 * PI / 180) + y * cos(60 * PI / 180);
}

bool eq(double a, double b) {
	return fabs(a - b) < EPS;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		unordered_map<double, int> seen[N];

		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i];
		}

		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (i != j) {
				seen[i][(X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j])] += 1;				
			}
		}

		for (int p = 0; p < N; p++) {
			for (auto i: seen[p]) {
				if (i.second >= 2) {
					ans += (i.second * (i.second - 1)) / 2;
				}
			}
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}
