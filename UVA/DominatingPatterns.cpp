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

char pat[160][100], ned[1000007];

int main(void) {
	for ( ; scanf("%d", &N) == 0 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%s", pat[i]);
		}
		scanf("%s", ned);

		int best = 0;
		vector<int> id;

		for (int i = 0; i < N; i++) {
			int curr = func(i);

			if (curr > best) {
				best = curr;

				id.clear();
				id.push_back(i);
			} else if (curr == best) {
				id.push_back(i);
			}
		}

		printf("%d\n", best);

		for (int i = 0; i < (int) id.size(); i++) {
			printf("%s\n", pat[id[i]]);
		}
	}
    return 0;
}
