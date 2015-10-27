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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1000006;

Int N;
bool P[MAXN];
vector<int> primes;

Int my_pow(int base, int exp) {
	Int ans = 1LL;

	for (int i = 0; i < exp; i++) {
		ans *= base;
	}
	
	return ans;
}

int main(void) {
	cin >> N;

	for (int i = 2; i <= (int) sqrt(N); i++) {
		if (!P[i]) {
			primes.push_back(i);
			
			for (Int j = i * (Int) i; j <= N; j += i) {
				P[j] = true;
			}
		}
	}

	Int ans = 1;

	for (int i = 0; i < (int) primes.size(); i++) {
		if (N % primes[i] == 0) {
			int pw = 0;
			
			while (N % primes[i] == 0) {
				N /= primes[i];
				pw += 1;
			}

			if (pw % 2 == 0) {
				ans *= my_pow(primes[i], pw - 1);
			} else {
				ans *= my_pow(primes[i], pw);
			}
		}
	}

	ans *= N;

	cout << ans << "\n";
	
	return 0;
}
