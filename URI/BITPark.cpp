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

const int MAXN = 2551805 / 2 + 1;
const int MAXS = 2000005;

const double EPS = 1e-7;

const double RATIO = 2.0 / 11.0;

int N, E;
int PA[MAXN], PB[MAXN];
char buff[50];
char kind;

struct FenwickTree {
	int tree[MAXS + 2];

	void clear(void) {
		memset(tree, 0, sizeof(tree));
	}

	void add(int id, int sum) {
		for (int i = id; i <= MAXS; i += (i & -i)) {
			tree[i] += sum;
		}
	}

	int sum(int id) {
		if (id == 0) return 0;

		int ans = 0;

		for (int i = id; i > 0; i -= (i & -i)) {
			ans += tree[i];
		}

		return ans;
	}
};

FenwickTree tA, tB;

bool isOffside(char team, int pos) {
	int sum;
	if (team == 'A') {
		sum = tB.sum(2000001) - tB.sum(PA[pos]);
	} else {
		sum = tA.sum(PB[pos] - 1);
	}
	
	double perc = sum * 100.0 / (N / 2.0);

	int d = lcm(11, N / 2);


	if (d / (N / 2) * sum < d / 11 * 2) {
		return true;
	}

	return false;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &E) == 2 && !(N == 0 && E == 0); ) {
		int sA = 0, sB = 0;

		tA.clear();
		tB.clear();

		for (int i = 1; i <= N / 2; i++) {
			scanf("%d", &PA[i]);
			PA[i] += 1;
			tA.add(PA[i], 1);
		}
		for (int i = 1; i <= N / 2; i++) {
			scanf("%d", &PB[i]);
			PB[i] += 1;
			tB.add(PB[i], 1);
		}

		string sp;
		int pos, next_location;

		bool offside = false;

		char hold_team;
		int hold_num = -1;

		for ( ; E--; ) {
			scanf(" %c", &kind);

			if (kind == 'I') {
				scanf("%s", buff);
				sp = string(buff);

				hold_team = sp[0];
				hold_num = stoi(sp.substr(1));				
				
				offside = false;

				if (isOffside(hold_team, hold_num)) {
					offside = true;
				}
			} else if (kind == 'M') {
				scanf("%s%d", buff, &next_location);
				next_location += 1;

				sp = string(buff); 
				pos = stoi(sp.substr(1));
				
				if (sp[0] == 'A') {
					tA.add(PA[pos], -1);
					PA[pos] = next_location;
					tA.add(PA[pos], 1);
				} else {
					tB.add(PB[pos], -1);
					PB[pos] = next_location;
					tB.add(PB[pos], 1);
				}
			} else if (kind == 'P') {
				scanf("%s", buff);

				if (offside) continue;

				sp = string(buff);
				pos = stoi(sp.substr(1));

				if (isOffside(sp[0], pos)) {
					offside = true;
				} else {
					hold_team = sp[0];
					hold_num = pos;
				}
			} else if (kind == 'G') {
				scanf("%s", buff);
				sp = string(buff);

				if (!offside) {
					if (sp == "A") {
						sB += 1;
					} else {
						sA += 1;
					}
				}
			} 
		}
		
		printf("%d X %d\n", sA, sB);
	}
    return 0;
}
