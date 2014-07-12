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

int N;

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

vector<point> convex_hull(vector<point> &P) {
    int n = P.size(), k = 0;
    vector<point> H(2*n);

    sort(P.begin(), P.end());

    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= /*change to < to remove equal points */ 0) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= /*change to < to remove equal points */ 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		vector<point> vp(N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &vp[i].x, &vp[i].y);
		}
		vector<point> ans = convex_hull(vp);
		ans.pop_back();

		printf("%d\n", (int) ans.size());

		for (int i = 0; i < (int) ans.size(); i++) {
			printf("%d %d\n", ans[i].x, ans[i].y);
		}
	}
    return 0;
}
