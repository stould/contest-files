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

const double INF = numeric_limits<double>::max();
const int MAXN = 12;

const double EPS = 1e-9;

int N;
double V;
double X[MAXN], Y[MAXN], Vx[MAXN], Vy[MAXN];

double calc_time(double sx, double sy, int id, double already) {
	double l = 0.0, h = 1010000100000.0, m;
	double ans = -1.0;

	double ex = X[id] + Vx[id] * already;
	double ey = Y[id] + Vy[id] * already;

	double A = (Vx[id] * Vx[id] + Vy[id] * Vy[id] - V * V);
	double B = 2.0 * Vx[id] * (ex - sx) + 2.0 * Vy[id] * (ey - sy);
	double C = sx * sx + sy * sy + ex * ex + ey * ey - 2.0 * (sx * ex + sy * ey);

	double delta = B * B - 4.0 * A * C;

	double x1 = (-B + sqrt(delta)) / (2.0 * A);
	double x2 = (-B - sqrt(delta)) / (2.0 * A);

	vector<double> s;
	
	if (x1 >= 0) s.push_back(x1);
	if (x2 >= 0) s.push_back(x2);

	sort(s.begin(), s.end());

	return s[0];

	/*	for (int x = 0; x < 70; x++) {
		m = (l + h) / 2.0;
		
		double next_x = X[id] + (Vx[id] * (already + m));
		double next_y = Y[id] + (Vy[id] * (already + m));

		double dst = hypot(sx - next_x, sy - next_y);


		double spent = dst / V;

		if (spent <= m) {
			if (ans < 0.0 || m < ans) {
				ans = m;
			}
			h = m;
		} else {
			l = m;
		}

		if (fabs(spent - m) < EPS) break;
	}
	
	double next_x = X[id] + (Vx[id] * (already + ans));
	double next_y = Y[id] + (Vy[id] * (already + ans));

	//	printf("%.2lf %.2lf - %.2lf %.2lf - %.2lf %.2lf\n", sx, sy, next_x, next_y, ans, hypot(sx - next_x, sy - next_y));

 	return ans;
	*/
}

double func(void) {
	double ans = INF;
	vector<int> pos(N + 1);

	for (int i = 0; i <= N; i++) {
		pos[i] = i;
	}

	do {
		double curr_x = X[0];
		double curr_y = Y[0];

		double t = 0.0;

		for (int i = 1; i <= N; i++) {
			double goal_x = X[pos[i]] + Vx[pos[i]] * t;
			double goal_y = Y[pos[i]] + Vy[pos[i]] * t;
			
			double spent = calc_time(curr_x, curr_y, pos[i], t);

			t += spent;
			t += 3600;

			curr_x = X[pos[i]] + Vx[pos[i]] * t;
			curr_y = Y[pos[i]] + Vy[pos[i]] * t;
		}
		
		t += calc_time(curr_x, curr_y, pos[0], t);
		ans = min(ans, ceil(t));
	} while (next_permutation(pos.begin() + 1, pos.end()));

	return ans;
}

int main(void) {
	int test = 1;
	for ( ; scanf("%d", &N) && N != 0; ) {
		for (int i = 1; i <= N; i++) {
			scanf("%lf%lf%lf%lf", &X[i], &Y[i], &Vx[i], &Vy[i]);

			Vx[i] /= 3600.0;
			Vy[i] /= 3600.0;
		}

		scanf("%lf%lf%lf", &X[0], &Y[0], &V);
		
		V /= 3600.0;
		
		Int ans = (Int) (func());

		int h = (ans / 3600);
		int m = (ans % 3600) / 60;
		int s = ans % 60;
		
		printf("Case %d: %d hour(s) %d minute(s) %d second(s)\n", test++, h, m, s);		
	}
    return 0;
}
