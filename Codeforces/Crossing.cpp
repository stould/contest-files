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

const int MAXN = 4000006;

int N, A, B;
int P[MAXN];
Int tree[MAXN];

void add(int id, Int value) {
	for (int i = id; i <= N; i += (i & -i)) {
		tree[i] += value;
	}
}

Int sum(int id) {
	Int ans = 0LL;
	for (int i = id; i > 0; i -= (i & -i)) {
		ans += tree[i];
	}
	return ans;
}

int main(void) {
	int test = 1;
	for ( ; scanf("%d%d%d", &N, &A, &B) == 3 && !(N == 0 && A == 0 && B == 0); ) {
		memset(tree, 0LL, sizeof(tree));
		Int ans = 0;
		for (int i = 0; i < N; i++) {
			P[i] = (int) ((Int) ((A * i + B) % N) + N) % N;
			ans += sum(N) - sum(P[i] + 1);
			add(P[i] + 1, 1);
		}
		cout << "Case " << test++ << ": " << ans << "\n";
	}
    return 0;
}
