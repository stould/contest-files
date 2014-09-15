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

int main(void) {
	scanf("%d", &T);
	for ( ; T--; ) {
		scanf("%d", &N);
		
		vector<point> P(N);

		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i].x, &P[i].y);			
		}

		int ans = 0;

		for (int i = 0; i < N; i++) {
			int hor = 1, ver = 1;
			int c = 1;

			map<double, int> mp;

			for (int j = 0; j < N; j++) {
				if (i != j) {
					if (P[i].x == P[j].x) {
						hor += 1;
					} else if (P[i].y == P[j].y) {
						ver += 1;
					} else {
						double cof = (P[j].y - P[i].y) / (double) (P[j].x - P[i].x);

						mp[cof] += 1;

						chmax(ans, mp[cof] + 1);
					}
				}
			}

			chmax(ans, hor);
			chmax(ans, ver);
		}

		printf("%d\n", ans);
	}
    return 0;
}
