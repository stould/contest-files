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

struct interval {
	int id;
	int l, r;

	interval(){}

	interval(int id, int l, int r):
		id(id),
		l(l),
		r(r) {}

	bool operator<(const interval& other) const {
		return (l != other.l) ? (l < other.l) : (r < other.r);
	}
};

int N, M;
vector<interval> met[22];

int main(void) {
	cin >> N >> M;

	int A, B, D;
	
	for (int i = 0; i < N; i++) {
		cin >> A >> B >> D;

		met[D].push_back(interval(i + 1, A, B));
	}

	for (int i = 1; i <= M; i++) {
		sort(met[i].begin(), met[i].end());

		int f = -1;
		int s = -1;
		
		if (met[i].size() > 1) {
			for (int j = 0; j < (int) met[i].size() - 1; j++) {
				if (met[i][j].r < met[i][met[i].size() - 1].l) {
					f = met[i][j].id;
					s = met[i][met[i].size() - 1].id;
				}
			}
		}
		
		if (f != -1) {
			cout << "TAK " << f << " " << s << endl;
		} else {
			cout << "NIE" << endl;
		}
	}
	
    return 0;
}
