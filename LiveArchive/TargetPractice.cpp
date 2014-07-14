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

const double EPS = 1e-9;

int N, M, ans;
vector<Int> pool;

struct pole {
	int x, y, h;

	pole(){}

	pole(int x, int y, int h): x(x), y(y), h(h) {}
};

double cross(pole A, pole B, pole C) {
    return (double) (B.x-A.x) * (C.y-A.y) - (B.y-A.y) * (C.x-A.x);
}


bool col(pole a, pole b, pole c) {
	return cross(a, b, c) == 0;
}

bool cmp(Int a, Int b) {
	return __builtin_popcountll(a) > __builtin_popcountll(b);
}

void rec(int id, Int mask, int spent) {
	int used = __builtin_popcountll(mask);
		
	if (id == M || spent >= ans) return;
	
	chmin(ans, spent + (N - used + 1) / 2);
	int next = __builtin_popcountll(pool[id]);
	
	if (spent + ((N - used + next - 1) / next) >= ans) return;

	rec(id + 1, mask | pool[id], spent + 1);
	rec(id + 1, mask, spent);	
}

int main(void) {
	int t = 1;
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		vector<pole> vp(N);
		set<Int> spool;

		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &vp[i].x, &vp[i].y, &vp[i].h);
		}

		for (int i = 0; i < N; i++) {
			spool.insert((Int) (1LL << i));
			for (int j = i + 1; j < N; j++) {
				if (i != j) {
					Int mask = (1LL << i) | (1LL << j);

					for (int k = 0; k < N; k++) {
						if (k != i && k != j) {
							if (col(vp[i], vp[j], vp[k])) {
								mask |= (1LL << k);
							}
						}
					}
					spool.insert(mask);
				}
			}
		}
		pool = vector<Int>(spool.begin(), spool.end());
		sort(pool.begin(), pool.end(), cmp);
		ans = (N + 1) / 2;
		M = (int) pool.size();

		rec(0, 0LL, 0);

		printf("Target set %d can be cleared using only %d shots.\n", t++, ans);		
	}
    return 0;
}
