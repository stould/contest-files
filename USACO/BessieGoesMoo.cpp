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
unordered_map<char, vector<int> > M;

int main(void) {
	freopen("bgm.in", "r", stdin);
	freopen("bgm.out", "w", stdout);
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char C;
		int V;
		scanf(" %c%d", &C, &V);

		M[C].push_back(V);
	}

	int ans = 0;

	for (auto B : M['B']) {
		for (auto E : M['E']) {
			for (auto S : M['S']) {
				for (auto I : M['I']) {
					for (auto G : M['G']) {
						for (auto O : M['O']) {
							for (auto m : M['M']) {
								Int s = (B + E + 2 * S + I + E) * (G + O + E + S) * (m + 2 * O);

								if (s % 7 == 0) {
									ans += 1;
								}
							}
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans);
	
    return 0;
}
