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

const int MAXN = 1000005;

Int N;
bool p[MAXN];
vector<int> primes;

void sieve() {
	for (Int i = 2; i < MAXN; i++) {
		if (!p[i]) {
			for (Int j = i * i; j < MAXN; j += i) {
				p[j] = true;
			}
			primes.push_back(i);
		}
	}
}

vector<pair<int, int> > decomp(Int x) {
	vector<pair<int, int> > ans;
	
	for (int i = 0; i < (int) primes.size(); i++) {
		if (x == 1) break;
		if (x % primes[i] == 0) {
			int p = 0;

			while (x % primes[i] == 0) {
				x /= primes[i];
				p += 1;
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
	sieve();

	while (cin >> N && N != 0) {
		bool isNeg = N < 0;

		if (N < 0) N = -N;
		
		vector<pair<int, int> > now = decomp(N);

		int ans = 0;		
		
		for (int i = 0; i < (int) now.size(); i++) {
			//if (isNeg && now[i].second % 2 == 0) continue;
			//chmin(ans, now[i].second);
			ans = gcd(ans, now[i].second);
			//cout << now[i].first << " " << now[i].second << "\n";
		}

		if (isNeg && ans % 2 == 0) {
			for (int i = ans; i >= 1; i--) {
				if (ans % i == 0 && i % 2 == 1) {
					ans = i;
					break;
				}
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}
