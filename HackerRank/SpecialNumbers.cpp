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

const int MAXN = 100005;
int N;
int cnt[MAXN], d[MAXN];
bool p[MAXN];
vector<int> primes;

void build(void) {
	memset(p, true, sizeof(p));
	for (int i = 2; i < MAXN; i++) {
		if (p[i]) {
			for (int j = i * i; j > 0 && j < MAXN; j += i) {
				p[j] = false;
			}
			primes.push_back(i);
		}
	}
}
int func(int x) {
	int ans = 1;

	if (x == 1) return ans;

	for (int i = 0; i < (int) primes.size(); i++) {
		if (x <= 1) {
			break;
		}
		if (x % primes[i] == 0) {
			int p = 0;

			while (x % primes[i] == 0) {
				p += 1;
				x /= primes[i];
			}
			ans *= (p + 1);
		}
	}
	return ans + 1;
}

int main(void) {
	build();
	cin >> N;

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		d[i] = func(i);

		if (cnt[d[i]] == 0) {
			ans += i;
		}
		cnt[d[i]] += 1;
	}
	cout << ans << endl;
    return 0;
}
