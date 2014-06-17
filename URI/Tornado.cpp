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

const int MAXN = 5050;

int N;
int P[MAXN];

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		vector<int> ps;
		
		int st = 0;
		for ( ; st < N && P[st] == 0; ) {
			st += 1;
		}
		if (st == N) {
			printf("%d\n", (int) round(N / 2.0));
		} else {
			for (int i = st; i < N; i++) {
				ps.push_back(P[i]);
			}
			for (int i = 0; i < st; i++) {
				ps.push_back(0);
			}
			int ans = 0;
			for (int i = 0; i < N; i++) {
				int s = i, ok = 0;
				while (ps[s] == 0 && s < N) {
					s += 1;
					ok = 1;
				}
				if (ok) {
					ans += (s - i) / 2.0;					
					i = s;
				}
			}
			printf("%d\n", ans);
		}
	}
    return 0;
}
