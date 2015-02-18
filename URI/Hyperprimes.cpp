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

const int MAXN = 2000005;

int N;
bool B[MAXN];
vector<int> primes;

int tree[MAXN];

void add(int id, int s) {
	for (int i = id; i < MAXN; i += (i & -i)) {
		tree[i] += s;
	}
}

int sum(int id) {
	int ans = 0;

	for (int i = id; i > 0; i -= (i & -i)) {
		ans += tree[i];
	}
	
	return ans;
}

int cnt(int x) {
	int ans = 1, id = 0;

	for ( ; x > 1 && id < (int) primes.size(); ) {
		if (x % primes[id] == 0) {
			int c = 0;

			while (x % primes[id] == 0) {
				c += 1;
				x /= primes[id];
			}
			ans *= (c + 1);
		}
		id += 1;
	}
	
	return ans;
}

void build(void) {
	memset(B, true, sizeof(B));
	for (int i = 2; i <= sqrt(MAXN); i++) {
		if (B[i]) {
			for (int j = i * i; j < MAXN && j > 0; j += i) {
				B[j] = false;
			}
		}
	}
	for (int i = 2; i < MAXN; i++) {
		if (B[i]) {
			primes.push_back(i);
			add(i, 1);
		}
	}
	for (int i = 2; i * (Int) i <= (Int) MAXN; i++) {
		if (B[cnt(i * i)]) {
			int s = sum(i * i) - sum(i * i - 1);
			if (s == 0) {
				add(i * i, 1);
			}
		}
	}
}

int main(void) {
	build();
	for ( ; scanf("%d", &N) == 1; ) {
		printf("%d\n", sum(N));
	}
    return 0;
}
