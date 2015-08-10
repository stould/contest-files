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

const int MAXN = 200005;

int N, K, A, M;
int P[MAXN];

int main(void) {
	cin >> N >> K >> A >> M;

	set<int> pos;
	set<int>::iterator it;
	int freepos = N - K * A;
	
	for (int i = 0; i < M; i++) {
		cin >> P[i];

		bool l = false;
		bool r = false;
		
		it = pos.lower_bound(P[i]);

		if (it != pos.end()) {
			int val = *it;
			if (abs(P[i] - val) <= A) {
				l = true;
			}
		}
		it = pos.upper_bound(P[i]);

		if (it != pos.end()) {
			int val = *it;
			if (abs(P[i] - val) <= A) {
				r = true;
			}
		}
		pos.insert(P[i]);
		freepos -= 1;
		if (l && r || freepos < 0) {
			cout << i + 1 << "\n";
			return 0;
		}
		//cout << i << " " << P[i] << " " << l << " " << r << "\n";
	}
	cout << "-1\n";
	return 0;
}
