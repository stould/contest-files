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

const int MAXN = 500005;

int N;
Int P[MAXN], L[MAXN], R[MAXN];

Int tree[MAXN];

void add(int id, Int v) {
	for (int i = id; i < MAXN; i += (i & -i)) {
		tree[i] += v;
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
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		L[i] = P[i] + L[i - 1];
	}
	
	Int G = L[N] / 3LL;
	Int ans = 0;

	if (L[N] % 3 == 0) {
		for (int i = N; i >= 1; i--) {
			R[i] = R[i + 1] + P[i];
			
			if (L[i] == G) {
				add(i, 1);
			}
		}
		
		for (int i = N; i >= 1; i--) {
			if (R[i] == G) {
			ans += sum(i - 2);
			}
		}
	}
	
	cout << ans << "\n";
		
    return 0;
}
