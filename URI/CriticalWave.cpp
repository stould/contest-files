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

const int MAXN = 1010;

int N;

inline void rd(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}

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

point P[MAXN];
int dp[MAXN][2];

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i].x, &P[i].y);
		}

		sort(P, P + N);

		int ans = 0;

		for (int i = 0; i < N; i++) {
			//0 = low, 1 = high
			dp[i][0] = dp[i][1] = 1;

			for (int j = 0; j < i; j++) {
				if (P[i].x == P[j].x) continue;
				if (P[i].y == P[j].y - 2) {
					chmax(dp[i][0], dp[j][1] + 1);
				}
				if (P[i].y == P[j].y + 2) {
					chmax(dp[i][1], dp[j][0] + 1);
				}
			}

			chmax(ans, dp[i][0]);
			chmax(ans, dp[i][1]);
		}

		printf("%d\n", ans);
	}
    return 0;
}
