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

const double G = 9.80665;
const double PI = 3.14159;

int N;
double H, P1, P2, V, alpha;

int main(void) {
	for ( ; scanf("%lf", &H) == 1; ) {
		scanf("%lf%lf%d", &P1, &P2, &N);
		for (int i = 0; i < N; i++) {
			scanf("%lf%lf", &alpha, &V);

			double a = -0.5 * G, b = V * cos(alpha * PI / 180.0), c = H;
			
			double x1 = (-b + sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
			double x2 = (-b - sqrt(b * b - 4.0 * a * c)) / (2.0 * a);

			double goal = max(x1, x2) * V * sin(alpha * PI / 180.0);

			bool ok = false;
			if (goal >= P1 && goal <= P2) {
				ok = true;
			}
			printf("%.5lf -> %s\n", goal, ok ? "DUCK" : "NUCK");
		}
	}
    return 0;
}
