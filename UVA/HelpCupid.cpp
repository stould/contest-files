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
map<int, int> cnt;

int main(void) {
	for ( ; cin >> N; ) {
		cnt.clear();
		int P;
		for (int i = 0; i < N; i++) {
			cin >> P;
			cnt[P] += 1;
		}
		vector<int> ps;

		for (int i = -11; i <= 12; i++) {
			if (cnt[i] % 2 == 1) {
				ps.push_back(i);
			}
		}

		int ansA = 0;
		int ansB = 0;

		int L = (int) ps.size();
		
		for (int i = 0; i < L; i += 2) {
			ansA += min(abs(ps[i] - ps[(i + 1) % L]), 24 - abs(ps[i] - ps[(i + 1) % L]));
		}
		for (int i = 1; i < L; i += 2) {
			ansB += min(abs(ps[i] - ps[(i + 1) % L]), 24 - abs(ps[i] - ps[(i + 1) % L]));
		}
		

		cout << min(ansA, ansB) << "\n";
	}
    return 0;
}
