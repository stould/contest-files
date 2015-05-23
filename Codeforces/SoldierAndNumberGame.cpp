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

const int MAXN = 5000005;

int T;
int A, B;
bool p[MAXN];
Int sum[MAXN];
vector<int> primes;
int cst[MAXN];

void build(void) {
	for (int i = 2; i < MAXN; i++) {
		if (!p[i]) {
			primes.push_back(i);
			for (Int j = i * (Int) i; j < MAXN; j += i) {
				p[j] = true;
			}
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	
	build();
	
	for (int i = 0; i < primes.size(); i++) {
		Int curr = primes[i];
		
		for ( ; ; ) {
			for (Int x = curr; x < MAXN; x += curr) {
				cst[x] += 1;
			}
			if (curr * (Int) primes[i] > MAXN) break;
			curr *= (Int) primes[i];
		}
	}

	for (int i = 1; i < MAXN; i++) {
		sum[i] = sum[i - 1] + cst[i];
	}

	for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		
		Int ans = sum[A] - sum[B];
		
		cout << ans <<"\n";
	}
    return 0;
}
