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

const int MAX_V = 10000000;

int T, A, B, K;
bool is_prime[MAX_V + 10];
int cnt[MAX_V + 10];
vector<int> primes;

int countDiv(int x) {
	int ans = 0;

	for (int i = 0; i < (int) primes.size(); i++) {
		int curr = 0;
		
		while (x % primes[i] == 0) {
			x /= primes[i];
			curr += 1;
		}
		if (curr > 0) {
			ans += 1;
		}
	}	
	
	return ans;
}

int main(void) {
	cin >> T;

	memset(is_prime, true, sizeof(is_prime));
	
	for (int i = 2; i <= MAX_V; i++) {
		if (is_prime[i]) {
			for (Int j = i * i; j >= 2 && j <= MAX_V; j += i) {
				is_prime[j] = false;
			}
			primes.push_back(i);
		}
	}

	for (int i = 0; i < (int) primes.size(); i++) {
		for (Int x = primes[i]; x <= MAX_V; x += primes[i]) {
			cnt[x] += 1;
		}
	}
	
	for (int t = 1; t <= T; t++) {
		cin >> A >> B >> K;

		int ans = 0;

		for (int i = A; i <= B; i++) {
			if (cnt[i] == K) {
				ans += 1;
			}
		}

		cout << "Case #" << t << ": " << ans << "\n";
		
	}
    return 0;
}
