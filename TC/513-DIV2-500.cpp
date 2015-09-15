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

class YetAnotherIncredibleMachine {
public:
	int countWays(vector <int>, vector <int>, vector <int>);
};

const Int MOD = 1000000009LL;

int YetAnotherIncredibleMachine::countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
	int N = (int) platformMount.size();
	int M = (int) balls.size();
	Int ans = 1LL;
	
	bool possible = true;
	
	for (int i = 0; i < N; i++) {
		int can = 0;
		for (int k = platformMount[i] - platformLength[i]; k <= platformMount[i]; k++) {
			bool valid = true;
			for (int j = 0; j < M; j++) {		
				if (balls[j] >= k && balls[j] <= k + platformLength[i]) {
					valid = false;
				}
			}
			if (valid) {
				can += 1;
			}
		}
		if (can == 0) {
			possible = false;
		} else {
			ans = ans * (Int) can;
			ans %= MOD;
		}		
	}
	
	if (!possible) {
		ans = 0LL;
	}
	
	ans = ((ans % MOD) + MOD) % MOD;
	
	return (int) ans;
}

//Powered by [KawigiEdit] 2.0!
