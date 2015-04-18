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

int T, N;

struct point {
    int x, y;
    point(int x, int y): x(x), y(y){}
    point(){}
    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator==(const point &p) const {
        return x == p.x && y == p.y;
    }
};
Int cross(const point &O, const point &A, const point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<point> convex_hull(vector<point> P) {
    int n = P.size(), k = 0;
    vector<point> H(2*n);

    sort(P.begin(), P.end());

    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < /*change to < to remove equal points */ 0) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) < /*change to < to remove equal points */ 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

bool func(vector<point> vi, point x) {
	vector<point> cv = convex_hull(vi);

	for (int i = 0; i < (int) cv.size(); i++) {
		if (x == cv[i]) return true;
	}
	return false;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		vector<point> P(N);

		for (int i = 0; i < N; i++) {
			cin >> P[i].x >> P[i].y;
		}

		cout << "Case #" << t << ":" << endl;

		vector<point> all = convex_hull(P);

		for (int i = 0; i < N; i++) {
			int best = 10000;

			if (func(all, P[i])) {
				best = 0;
			} else {
				for (int x = 1; x < (1 << N); x++) {
					if ((x & (1 << i))) {
						vector<point> vc;
						
						for (int j = 0; j < N; j++) {
							if (x & (1 << j)) {
								vc.push_back(P[j]);
							}
						}
						vector<point> cvi = convex_hull(vc);
						
						if (func(cvi, P[i])) {
							chmin(best, N - (int) vc.size());
						}
					}
				}
			}
			cout << best << endl;
		}
	}
    return 0;
}
