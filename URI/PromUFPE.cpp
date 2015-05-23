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

int T, N;
bool p[MAXN];
vector<int> primes;

void build(void) {
	for (int i = 2; i < sqrt(MAXN); i++) {
		if (!p[i]) {
			for (Int j = i * (Int) i; j < MAXN; j += i) {
				p[j] = true;
			}
		}
	}
	for (int i = 2; i < MAXN; i++) {
		if (!p[i]) {
			primes.push_back(i);
		}
	}
}

vector<pair<int, int> > decomp(int x) {
	vector<pair<int, int> > ans;

	for (int i = 0; i < (int) primes.size(); i++) {
		if (x % primes[i] == 0) {
			int p = 0;

			while (x % primes[i] == 0) {
				p += 1;
				x /= primes[i];
			}

			ans.push_back(make_pair(primes[i], p));
		}
	}
	if (x != 1) {
		ans.push_back(make_pair(x, 1));
	}
	return ans;
}

int main(void) {
	build();
	/*
	for (int i = 1; i < 20; i++) {
		vector<pair<int, int> > dc = decomp(i*i);

		cout << i*i << "\n";
		for (int i = 0; i < (int) dc.size(); i++) {
			cout << dc[i].first << " - " << dc[i].second << "\n" ;
		}
	}
	return 0;
	*/
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		vector<pair<int, int> > dc = decomp(N);
		
		Int ans = 1;

		for (int i = 0; i < (int) dc.size(); i++) {
			for (int j = 0; j < dc[i].second; j++) {
				ans *= dc[i].first;
			}
			if (dc[i].second % 2 == 1) {
				ans *= dc[i].first;
			}
		}

		cout << "Caso #" << t << ": " << ans << "\n";
	}
    return 0;
}
