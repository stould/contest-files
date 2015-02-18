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

const int MAXN = 5560;
const Int MAXV = 100000000000000000LL;

int T;
Int N;

bool p[MAXN];
vector<int> primes;

void build(void) {
	memset(p, true, sizeof(p));

	for (int i = 2; i <= MAXN; i++) {
		if (p[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= MAXN; j += i) {
				p[j] = false;
			}
		}
	}
}

int func(Int x) {
	int ans = 1;

	for (int i = 0; i < (int) primes.size() && x > 1; i++) {
		if (x % primes[i] == 0) {
			int curr = 0;
			while (x % primes[i] == 0) {
				x /= primes[i];
				curr += 1;
			}
			ans *= (curr + 1);
		}
	}
	return ans;
}

set<Int> st;

void go(int id, Int v, int last) {
	Int base = primes[id];
	if (v > MAXV) return;
	st.insert(v);

	for (int i = 0; i <= last; i++) {
		v *= (Int) base;
		if (v > MAXV) break;
		go(id + 1, v, i);
	}
}

int main(void) {
	scanf("%d", &T);

	build();
	go(0, 1LL, 64);

	int curr = 0;
	vector<Int> ans;

	for (set<Int>::iterator it = st.begin(); it != st.end(); it++) {
		int s = func(*it);

		if (s > curr) {
			ans.push_back(*it);
			curr = s;
		}
	}

	for ( ; T--; ) {
		cin >> N;
		int l = 0, h = ans.size(), m;
		Int p = -1;
		for ( ; l <= h; ) {
			m = (l + h) / 2;

			if (ans[m] > N) {
				h = m - 1;
			} else {
				l = m + 1;
				chmax(p, ans[m]);
			}
		}
		cout << p << "\n";
	}
    return 0;
}
