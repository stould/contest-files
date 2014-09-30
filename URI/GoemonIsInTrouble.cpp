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

const int MAXN = 10004;

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

struct line {
	point a, b;
	bool v, h;
	double ca, cl;

	line(const point _a, const point _b) {
		a = _a;
		b = _b;

		if (a.x == b.x) {
			h = true;
		} else {
			h = false;
		}
		if (a.y == b.y) {
			v = true;
		} else {
			v = false;
		}
		
		if (!h) {
			ca = (b.y - a.y) / (double) (b.x - a.x);
			cl = b.y - ca * b.x;
		}
	}	
};
	
int T, P, G;
point bomb, GM[MAXN];
pair<int, int> W[MAXN];

//check point above the line
bool above(line l, point p) {
	if (l.h) {
		if (p.y > l.a.y) return true;
	} else {
		int py = p.x * l.ca + l.cl;
		
		if (py < p.y) return true;
	}
	return false;
}

//check point below the line
bool below(line l, point p) {
	if (l.h) {
		if (p.y < l.a.y) return true;
	} else {
		int py = p.x * l.ca + l.cl;
		
		if (py > p.y) return true;
	}
	return false;
}

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> bomb.x >> bomb.y >> P;

		for (int i = 0; i < P; i++) {
			cin >> W[i].first >> W[i].second;
		}

		cin >> G;

		for (int i = 0; i < G; i++) {
			cin >> GM[i].x >> GM[i].y;
		}

		sort(W, W + P);
		sort(GM, GM + G);

		int ans = 0, pg = 0;

		for (int i = 0; pg < G && i < P; i++) {
			line l1(bomb, point(0, W[i].first));
			line l2(bomb, point(0, W[i].second));

			while (pg < G && below(l2, GM[pg])) {				
				if (above(l1, GM[pg])) {
					ans += 1;				
				} 
				pg++;
			}
			pg--;
		}


		cout << ans << "\n";
	}

    return 0;
}
